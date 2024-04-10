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
char a[maxn],b[maxn][maxn];
int n,c[maxn],m,len;
int f[maxn][maxn],tlen[maxn];
bool iszero[maxn];
int rk[maxn][maxn],sa[maxn][maxn];
vector<pin> tong[maxn];
const int inf=2e9;
int main(){
    scanf("%s",a+1);len=strlen(a+1);
    read(n);
    rep(i,1,n)scanf("%s",b[i]+1);
    m=strlen(a+1);
    rep(i,1,n)m=max(m,tlen[i]=(int)strlen(b[i]+1));
    rep(i,1,n)reverse(b[i]+1,b[i]+1+strlen(b[i]+1));
    rep(i,0,9)read(c[i]);bool dig=0;
    reverse(a+1,a+1+len);
    per(i,len,1){
    	if(a[i]<='9'&&a[i]>='0')dig=1;
    	if(a[i]=='?'&&!dig)iszero[i]=1,dig=1;
    }
    rep(i,1,n)rep(j,0,m)if(b[i][j]==0)b[i][j]='0';
    rep(i,1,m+1)if(a[i]==0)a[i]='0';
    rep(i,1,n)rk[i][0]=i;
    rep(i,1,n)sa[i][0]=i;
    rep(j,1,m+1){
    	rep(i,0,9)tong[i].clear();
    	rep(i,1,n)if(b[i][j]!=0)tong[b[i][j]-'0'].pb(mk(rk[i][j-1],i));
    	else tong[0].pb(mk(rk[i][j-1],i));
    	rep(i,0,9)sort(tong[i].begin(),tong[i].end());
  //  	rep(i,0,9)reverse(tong[i].begin(),tong[i].end());
    	int tot=0;
    	per(k,9,0){
    		for(pin x:tong[k]){
    			rk[x.w2][j]=++tot;
    			sa[tot][j]=x.w2;
    		}
    	}
    }
    rep(i,0,m+1)rep(j,0,n)f[i][j]=-inf;
    f[0][0]=0;
    rep(i,0,m-1){
    	rep(nxt,0,9){
    		if(iszero[i+1]&&nxt==0)continue;
    		if(a[i+1]!='?'&&(a[i+1]-'0')!=nxt)continue;
    		int cur=0;int nowv=0;
    		rep(k,1,n){
    			if(i+1<=max(len,tlen[k]))
	    			nowv+=c[(b[k][i+1]-'0'+nxt)%10];
    			if(b[k][i+1]-'0'+nxt>=10)cur=max(cur,rk[k][i+1]);
    		}f[i+1][cur]=max(f[i+1][cur],f[i][0]+nowv);
    		rep(j,1,n){
    			int pos=sa[j][i];
    			if(i+1<=max(len,tlen[pos]))
    				nowv-=c[(b[pos][i+1]-'0'+nxt)%10];
    			nowv+=c[(b[pos][i+1]-'0'+nxt+1)%10];
    			if(b[pos][i+1]-'0'+nxt+1>=10)cur=max(cur,rk[pos][i+1]);
    			f[i+1][cur]=max(f[i+1][cur],f[i][j]+nowv);
    		}
    	}
    }int ans=0;
    rep(i,0,n)ans=max(ans,f[m][i]+c[1]*i);
    cout<<ans;
    return 0;
}