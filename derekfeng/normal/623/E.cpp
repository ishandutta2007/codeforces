#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
const int M=1e9+7;
const db pi=acos(-1);
struct comp{
    db x,y;
    comp(db x=0,db y=0):x(x),y(y){}
    comp operator +(const comp &o){return comp(x+o.x,y+o.y);}
    comp operator -(const comp &o){return comp(x-o.x,y-o.y);}
    comp operator *(const comp &o){return comp(x*o.x-y*o.y,x*o.y+y*o.x);}    
    comp operator *(const db &o){return comp(x*o,y*o);}
    comp operator /(const db &o){return comp(x/o,y/o);}
};
comp I{0,1};
const int D=(1<<15);
int N,lg,rev[65540];
db COS[20],SIN[20];
void fft(comp *A,int t){
    for(int i=0;i<N;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for(int i=0;i<lg;i++){
        int mid=(1<<i);comp Wn{COS[i],t*SIN[i]};
        for(int j=0;j<N;j+=(mid<<1)){
            comp w{1,0};
            for(int k=0;k<mid;k++,w=w*Wn){
                comp x=A[j+k],y=w*A[j+mid+k];
                A[j+k]=x+y,A[j+mid+k]=x-y;
            }
        }
    }
    if(t<0)for(int i=0;i<N;i++)A[i]=A[i]/N;
}
void fftfft(comp *A,comp *B,int t){
    for(int i=0;i<N;i++)A[i].y=B[i].x;
    fft(A,t);B[0]=comp(A[0].x,-A[0].y);
    for(int i=1;i<N;i++)B[i]=comp(A[N-i].x,-A[N-i].y);
    for(int i=0;i<N;i++){
        comp x=A[i],y=B[i];
        A[i]=(x+y)*0.5,B[i]=(y-x)*0.5*I;
    }
}
ll rd(db x){return x<0?(ll)(x-0.5)%M:(ll)(x+0.5)%M;}
comp a0[65540],a1[65540],b0[65540],b1[65540],p[65540],q[65540];
vector<int>merge(const vector<int>A,const vector<int>B){
    int n=A.size()-1,m=B.size()-1;
    N=1,lg=0;while(N<=n+m)N<<=1,lg++;
    for(int i=0;i<N;i++)a0[i]=a1[i]=b0[i]=b1[i]=comp(0,0);
    for(int i=0;i<=n;i++)a0[i].x=A[i]/D,a1[i].x=A[i]%D;
    for(int i=0;i<=m;i++)b0[i].x=B[i]/D,b1[i].x=B[i]%D;
    for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    for(int i=0,mid=1;i<=lg;i++,mid<<=1)COS[i]=cos(pi/mid),SIN[i]=sin(pi/mid);
    fftfft(a0,a1,1),fftfft(b0,b1,1);
    for(int i=0;i<N;i++)p[i]=a0[i]*b0[i]+I*a1[i]*b0[i],q[i]=a0[i]*b1[i]+I*a1[i]*b1[i];
    fft(p,-1),fft(q,-1);vector<int>res;
    for(int i=0;i<=n+m;i++){
        int tmp=(((ll)D*D%M*rd(p[i].x)%M+(ll)D*(rd(p[i].y)+rd(q[i].x))%M)%M+rd(q[i].y))%M;
        res.push_back(tmp);
    }
    return res;
}
ll n;int K;
int fc[30005],iv[30005];
int myp(int x,int t){int a=1;for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;return a;}
struct info{vector<int>v;int len;info(){v.clear(),len=0;}};
info mul(info a,info b){
	int PW=myp(2,b.len),mul=1;
	info ans;for(int i=0;i<=K;i++)a.v[i]=(ll)a.v[i]*mul%M,mul=(ll)mul*PW%M;
	ans.v=merge(a.v,b.v);while(ans.v.size()>K+1)ans.v.pop_back();
	ans.len=a.len+b.len;return ans;
}
int main(){
	scanf("%lld%d",&n,&K);if(n>K){puts("0");return 0;}
	fc[0]=1;for(int i=1;i<=K;i++)fc[i]=(ll)fc[i-1]*i%M;
	iv[K]=myp(fc[K],M-2);for(int i=K;i;i--)iv[i-1]=(ll)iv[i]*i%M;
	info A,X;
	A.v.push_back(1);for(int i=1;i<=K;i++)A.v.push_back(0);
	X.len=1;X.v.push_back(0);for(int i=1;i<=K;i++)X.v.push_back(iv[i]);
	for(;n;n>>=1,X=mul(X,X))if(n&1)A=mul(A,X);
	int ans=0;for(int i=0;i<=K;i++)(ans+=(ll)A.v[i]*fc[K]%M*iv[K-i]%M)%=M;
	printf("%d",ans);
}