#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!


int pool[(int)5e7];int ps;
inline int *aloc(int x){
    ps+=x;return pool+ps-x;
}
void unit_monge_mult(int *a,int *b,int *r,int n){
    if(n==2){
        if(a[0]==0&&b[0]==0)r[0]=0,r[1]=1;
        else r[0]=1,r[1]=0;
        return;
    }
    if(n==1){r[0]=0;return;}
    int lps=ps;
    int d=n/2;
    int *a1=aloc(d),*a2=aloc(n-d),*b1=aloc(d),*b2=aloc(n-d);
    int *mpa1=aloc(d),*mpa2=aloc(n-d),*mpb1=aloc(d),*mpb2=aloc(n-d);
    int p[2]={0,0};
    for(int i=0;i<n;i++){
        if(a[i]<d)a1[p[0]]=a[i],mpa1[p[0]]=i,p[0]++;
        else a2[p[1]]=a[i]-d,mpa2[p[1]]=i,p[1]++;
    }
    p[0]=p[1]=0;
    for(int i=0;i<n;i++){
        if(b[i]<d)b1[p[0]]=b[i],mpb1[p[0]]=i,p[0]++;
        else b2[p[1]]=b[i]-d,mpb2[p[1]]=i,p[1]++;
    }
    int *c1=aloc(d),*c2=aloc(n-d);
    unit_monge_mult(a1,b1,c1,d),unit_monge_mult(a2,b2,c2,n-d);
    int *cpx=aloc(n),*cpy=aloc(n),*cqx=aloc(n),*cqy=aloc(n);
    for(int i=0;i<d;i++)cpx[mpa1[i]]=mpb1[c1[i]],cpy[mpa1[i]]=0;
    for(int i=0;i<n-d;i++)cpx[mpa2[i]]=mpb2[c2[i]],cpy[mpa2[i]]=1;
    for(int i=0;i<n;i++)r[i]=cpx[i];
    for(int i=0;i<n;i++)cqx[cpx[i]]=i,cqy[cpx[i]]=cpy[i];
    int hi=n,lo=n,his=0,los=0;
    for(int i=0;i<n;i++){
        if(cqy[i]^(cqx[i]>=hi))his--;
        while(hi>0&&his<0){
            hi--;
            if(cpy[hi]^(cpx[hi]>i))his++;
        }
        while(lo>0&&los<=0){
            lo--;
            if(cpy[lo]^(cpx[lo]>=i))los++;
        }
        if(los>0&&hi==lo)r[lo]=i;
        if(cqy[i]^(cqx[i]>=lo))los--;
    }
    ps=lps;return;
}
vector<int> subunit_monge_mult(const vector<int>&a,const vector<int>&b){
    ps=0;
    int n=a.size();
    int *za=aloc(n),*zb=aloc(n),*res=aloc(n),*vis=aloc(n),*mpa=aloc(n),*mpb=aloc(n),*rb=aloc(n);
    memset(vis,0,sizeof(int)*n);
    memset(mpa,-1,sizeof(int)*n);
    memset(mpb,-1,sizeof(int)*n);
    memset(rb,-1,sizeof(int)*n);
    int ca=n;
    for(int i=n-1;i>=0;i--)if(a[i]!=-1){
        vis[a[i]]=1;ca--;za[ca]=a[i];mpa[ca]=i;
    }
    for(int i=n-1;i>=0;i--)if(!vis[i])za[--ca]=i;
    memset(vis,-1,sizeof(int)*n);
    for(int i=0;i<n;i++)if(b[i]!=-1)vis[b[i]]=i;
    ca=0;
    for(int i=0;i<n;i++)if(vis[i]!=-1){
        mpb[ca]=i;rb[vis[i]]=ca++;
    }
    for(int i=0;i<n;i++)if(rb[i]==-1)rb[i]=ca++;
    for(int i=0;i<n;i++)zb[rb[i]]=i;
    unit_monge_mult(za,zb,res,n);
    vector<int> ret(n,-1);
    for(int i=0;i<n;i++)if(mpa[i]!=-1&&mpb[res[i]]!=-1)ret[mpa[i]]=mpb[res[i]];
    return ret;
}

const int maxn=35005;

int n,k;
int a[maxn];
int loc[maxn];
const int maxv=10;
int v[10];

const vector<int> addition_chains[]={
{},
{1},
{1,2},
{1,2,3},
{1,2,4},
{1,2,3,5},
{1,2,3,6},
{1,2,3,4,7},
{1,2,4,8},
{1,2,3,6,9},
{1,2,3,5,10},
{1,2,3,4,7,11},
{1,2,3,6,12},
{1,2,3,5,8,13},
{1,2,3,4,7,14},
{1,2,3,5,10,15},
{1,2,4,8,16},
{1,2,4,8,9,17},
{1,2,3,6,9,18},
{1,2,3,4,8,11,19},
{1,2,3,5,10,20},
{1,2,3,4,7,14,21},
{1,2,3,4,7,11,22},
{1,2,3,5,10,13,23},
{1,2,3,6,12,24},
{1,2,3,5,10,15,25},
{1,2,3,5,8,13,26},
{1,2,3,6,9,18,27},
{1,2,3,4,7,14,28},
{1,2,3,4,7,11,18,29},
{1,2,3,5,10,15,30},
{1,2,3,4,7,14,17,31},
{1,2,4,8,16,32},
{1,2,4,8,16,17,33},
{1,2,4,8,9,17,34},
{1,2,3,4,7,14,21,35},
{1,2,3,6,9,18,36},
{1,2,3,5,8,16,21,37},
{1,2,3,4,8,11,19,38},
{1,2,3,5,8,13,26,39},
{1,2,3,5,10,20,40},
{1,2,3,5,10,20,21,41},
{1,2,3,4,7,14,21,42},
{1,2,3,5,10,20,23,43},
{1,2,3,4,7,11,22,44},
{1,2,3,5,10,15,30,45},
{1,2,3,5,10,13,23,46},
{1,2,3,4,7,10,20,27,47},
{1,2,3,6,12,24,48},
{1,2,3,6,12,24,25,49},
{1,2,3,5,10,15,25,50}
};

vector<int> px[10];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> x(n,-1);
    for(int i=n-1;i>=0;i--){
        if(loc[a[i]])x[i]=loc[a[i]];
        loc[a[i]]=i;
    }
    px[0]=x;
    for(int j=1;j<(int)addition_chains[k].size();j++){
        int u=addition_chains[k][j];
        for(int j1=0;j1<j;j1++){
            for(int j2=0;j2<j;j2++){
                if(addition_chains[k][j1]+addition_chains[k][j2]==u){
                    px[j]=subunit_monge_mult(px[j1],px[j2]);
                    goto e;
                }
            }
        }
        e:;
    }
    int ans=n;
    for(int i=0;i<n;i++)ans-=px[addition_chains[k].size()-1][i]!=-1;
    cout<<ans;
    return 0;
}