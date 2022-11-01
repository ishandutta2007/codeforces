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
const int maxn=100005;
int a[maxn][42],k[maxn],n,m,cnt;
vector<pin> w[maxn];
pin b[maxn<<1];
int sum[45][45][45],gcd[45][45];
vector<int> fac[45];
inline void prprpr(){
	rep(i,1,40)for(int j=i;j<=40;j+=i)fac[j].pb(i);
	rep(i,1,40)rep(j,1,40)gcd[i][j]=__gcd(i,j);
}
inline void del(int x){
	for(int len:fac[k[b[x].w1]]){
		sum[k[b[x].w1]][len][b[x].w2%len]--;
	}
}
inline void add(int x){
	for(int len:fac[k[b[x].w1]]){
		sum[k[b[x].w1]][len][b[x].w2%len]++;
	}
}
inline int solve(int v){
	cnt=0;int ans=1;
	for(pin fsf:w[v])b[++cnt]=fsf;
	if(cnt==0)return 0;
	int last=1;add(1);
	rep(i,2,cnt){
		if(b[i].w1-b[i-1].w1>1){
			while(last<i)del(last++);
		}int tot=0;
		rep(v,1,40){
			tot+=sum[v][gcd[v][k[b[i].w1]]][b[i].w2%gcd[v][k[b[i].w1]]];
		}
		if(tot!=i-last){
			while(last<i){
				del(last++);
				int tot=0;
				rep(v,1,40){
					tot+=sum[v][gcd[v][k[b[i].w1]]][b[i].w2%gcd[v][k[b[i].w1]]];
				}
				if(tot==i-last)break;
			}
		}add(i);ans=max(ans,i-last+1);
	}
	while(last!=cnt)del(last++);del(cnt);
	assert(ans<=n);
	return ans;
}
int main(){
	prprpr();
	read(n);read(m);
	rep(i,1,n){
		read(k[i]);rep(j,1,k[i])read(a[i][j]);
	}
	rep(i,1,n){
		rep(j,1,k[i])w[a[i][j]].pb(mk(i,j));
	}
	rep(i,1,m)printf("%d\n",solve(i));
	return 0;
}