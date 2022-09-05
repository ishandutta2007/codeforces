#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000;
int n,a[N],b[N];char S[N];
vector<Pii>ans;ll res;
set<int>Set[2][10];
void Modify(int p, int x){
	Set[p&1][x].erase(p);Set[p&1][a[p]].insert(p);
	a[p]=x;
}
int main() {
	read(n);
	scanf("%s",S+1);rep(i,1,n)a[i]=S[i]-'0';
	scanf("%s",S+1);rep(i,1,n)b[i]=S[i]-'0';
	int tot=0;
	for(int i=1;i<=n;i+=2)tot+=a[i]-b[i];
	for(int i=2;i<=n;i+=2)tot-=a[i]-b[i];
	if(tot){puts("-1");return 0;}
	rep(i,0,1)rep(j,0,9)Set[i][j].insert(n+1);
	rep(i,1,n)rep(j,0,9)if(a[i]!=j)
		Set[i&1][j].insert(i);
	rep(i,1,n)while(a[i]!=b[i]){
		if(a[i]>b[i]){
			int p=min(*Set[i&1][9].upper_bound(i),*Set[(i&1)^1][0].upper_bound(i));
			res+=p-i;Modify(i,a[i]-1);Modify(p,(p-i&1)?a[p]-1:a[p]+1);
			if(SZ(ans)<1e5){
				per(j,p-1,i)ans.pb(Pii(j,j-i&1?1:-1));
			}
		}
		else{
			int p=min(*Set[i&1][0].upper_bound(i),*Set[(i&1)^1][9].upper_bound(i));
			res+=p-i;Modify(i,a[i]+1);Modify(p,(p-i&1)?a[p]+1:a[p]-1);
			if(SZ(ans)<1e5){
				per(j,p-1,i)ans.pb(Pii(j,j-i&1?-1:1));
			}
		}
	}
	
	
	if(res>1e5)ans.resize(1e5);
	printf("%lld\n",res);
	rep(i,0,SZ(ans)-1)
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}