#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=1005;
typedef double ld;
ld a[maxn][maxn],v[maxn],f[maxn],cnt[maxn];
bool used[maxn];
int n;const ld inf=1e100;
int main(){
    read(n);
    rep(i,1,n){
        f[i]=inf;cnt[i]=1;
        rep(j,1,n){
            int x;read(x);
            a[i][j]=x/100.;
        }
    }
    f[n]=0;
    rep(w,1,n){
        int k=0;
        rep(i,1,n)
            if((k==0)||(((!used[i])&&(f[i]<f[k]))))k=i;
        used[k]=1;
        rep(i,1,n)if(!used[i]){
            v[i]+=cnt[i]*a[i][k]*(f[k]+1);
            cnt[i]*=(1-a[i][k]);
            if(cnt[i]!=1)f[i]=min(f[i],(v[i]+cnt[i])/(1-cnt[i]));
        }
    }
    printf("%.12f\n",f[1]);
	return 0;
}