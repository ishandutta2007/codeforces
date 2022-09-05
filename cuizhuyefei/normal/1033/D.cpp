#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 66666,mo=998244353;
ll n,res=1;map<ll,ll>Map;
ll a[N],len,f[N],sz[N];
ll b[N],c[N],bot=1,top;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll power(ll a, ll b){
	if(b==2)return a*a;
	if(b==3)return a*a*a;
	if(b==4)return a*a*a*a;
	return a;
}
int dy(int a, int b){return a+b*len;}
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
void merge(int x, int y){x=find(x);y=find(y);f[x]=y;}
int getid(ll a, ll b){return 1.0*a*a>b+10||a*a>b;}//WA WA:inf too small-->b+10
void ins(ll x,ll y){rep(i,bot,top)if(b[i]==x){c[i]+=y;return;}b[++top]=x;c[top]=y;}
void erase(int p){rep(i,p,len-1)a[i]=a[i+1];len--;}//WA
int main() {
	read(n);rep(i,1,n){
		ll x;read(x);bool ok=0;
		per(j,4,2){
			ll y=pow(x,1.0/j);
			for(ll q=max(y-5,1LL);q<=y+5;q++)if(power(q,j)==x&&!ok){//WA
				ok=1;ins(q,j);//WA
			}
		}
		if(!ok)a[++len]=x;
	}
	while(bot<=top){//WA
		for(int i=1;i<=len;)if(a[i]%b[bot]==0){
			c[bot]++;ins(a[i]/b[bot],1);erase(i);
		}else i++;
	//	printf("%d:%d\n",b[bot],c[bot]);
		res=res*(c[bot]+1)%mo;b[bot]=c[bot]=0;bot++;//clear
	}
	rep(i,1,len)f[dy(i,0)]=dy(i,0),f[dy(i,1)]=dy(i,1);
	rep(i,1,len)rep(j,i+1,len){
		ll g=gcd(a[i],a[j]);
		if(a[i]==a[j])merge(dy(i,0),dy(j,0)),merge(dy(i,1),dy(j,1));
		else if(g>1) merge(dy(i,getid(g,a[i])),dy(j,getid(g,a[j])));//WA
	}
	rep(i,1,len*2)sz[find(i)]++;
	rep(i,1,len*2)res=res*(sz[i]+1)%mo;
	printf("%lld",res%mo);fflush(stdout);return 0;
}