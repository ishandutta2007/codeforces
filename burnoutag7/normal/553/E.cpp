#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1);

void fft(vector<complex<double>> &v,int inv){
    int n=v.size();
    static vector<int> r;
    r.resize(n);
    for(int i=0;i<n;i++){
        r[i]=r[i>>1]>>1;
        if(i&1)r[i]|=n>>1;
        if(r[i]>i)swap(v[i],v[r[i]]);
    }
    for(int i=2;i<=n;i*=2){
        complex<double> wn(cos(2*pi/i),sin(inv*2*pi/i));
        for(int j=0;j<n;j+=i){
            complex<double> w(1,0);
            for(int k=j;k<j+i/2;k++){
                complex<double> u=v[k],t=w*v[i/2+k];
                v[k]=u+t;
                v[i/2+k]=u-t;
                w*=wn;
            }
        }
    }
    if(inv==-1)for(int i=0;i<n;i++)v[i].real(v[i].real()/n);
}

vector<double> convolution(const vector<double> &a,const vector<double> &b){
    int n=1,m=a.size()+b.size()-1;
    while(n<m)n*=2;
    vector<complex<double>> va(n),vb(n);
    for(int i=0;i<a.size();i++)va[i].real(a[i]);
    for(int i=0;i<b.size();i++)vb[i].real(b[i]);
    fft(va,1);
    fft(vb,1);
    for(int i=0;i<n;i++)va[i]*=vb[i];
    fft(va,-1);
    vector<double> res(m);
    for(int i=0;i<m;i++)res[i]=va[i].real();
    return res;
}

namespace IO{
    const int SIZ=(1<<25);
    char buf1[SIZ],*p1=buf1,*p2=buf1;
    char buf2[SIZ],*p3=buf2,*p4=buf2;
    char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
}
void read(int &x){
    char c;
    while((c=IO::gchar())>'9'||c<'0');
    x=c-'0';
    while((c=IO::gchar())>='0'&&c<='9')x=x*10+c-'0';
}

const int inf=0x3f3f3f3f;
int n,m,t,x,u[105],v[105],w[105],d[55][55];
vector<double> p[105],fv[55],fe[105];

void sol(int l,int r){
    if(r<=t)return;
    if(l==r){
        for(int i=1;i<n;i++)fv[i][l]=inf;
        for(int i=1;i<=m;i++)if(u[i]!=n)fv[u[i]][l]=min(fv[u[i]][l],fe[i][l]+w[i]);
        return;
    }
    int mid=l+r>>1;
    sol(l,mid);
    for(int i=1;i<=m;i++)if(u[i]!=n){
        vector<double> a(fv[v[i]].begin()+l,fv[v[i]].begin()+mid+1),b(p[i].begin(),p[i].begin()+r-l+2);
        a=convolution(a,b);
        for(int j=mid+1;j<=r;j++)fe[i][j]+=a[j-l];
    }
    sol(mid+1,r);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    read(n);read(m);read(t);read(x);
    memset(d,inf,sizeof(d));
    for(int i=1;i<=n;i++)d[i][i]=0,fv[i].resize(2*t+1);
    for(int i=1;i<=m;i++){
        read(u[i]);read(v[i]);read(w[i]);
        d[u[i]][v[i]]=min(d[u[i]][v[i]],w[i]);
        p[i].resize(2*t+1);
        fe[i].resize(2*t+1);
        for(int j=1,x;j<=t;j++){
            read(x);
            p[i][j]=x/1e5;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=0;j<=t;j++)fv[i][j]=d[i][n]+x;
    fv[n][t]=0;
    sol(0,2*t);
    cout<<fixed<<setprecision(10)<<fv[1][2*t];

    return 0;
}