#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 340000;
int n,h[N],l[N],r[N],s[N],val[N];
vector<Pii> mrk[N];
multiset<int> Set;
int main() { 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	read(n); rep(i,1,n) read(h[i]),read(l[i]),read(r[i]);
	int len=0; rep(i,1,n) s[++len]=l[i],s[++len]=r[i];
	sort(s+1,s+len+1); len=unique(s+1,s+len+1)-s-1;
	rep(i,1,n) {
		mrk[lower_bound(s+1,s+len+1,l[i])-s].push_back(Pii(h[i],1));
		mrk[lower_bound(s+1,s+len+1,r[i])-s].push_back(Pii(h[i],-1));
	}
	rep(i,1,len-1) {
		per(j,SZ(mrk[i])-1,0)
			if (mrk[i][j].se==1) Set.insert(mrk[i][j].fi);
			else Set.erase(Set.find(mrk[i][j].fi));
	//	printf("%d : %d\n",i,SZ(Set));
		if (SZ(Set)) val[i]=*Set.rbegin(); //!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	vector<Pii> ans;
	rep(i,1,len) if (val[i]!=val[i-1]) {
		ans.push_back(Pii(s[i],val[i-1]));
		ans.push_back(Pii(s[i],val[i]));
	}
	len=SZ(ans); printf("%d\n",len);
	rep(i,0,len-1) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}