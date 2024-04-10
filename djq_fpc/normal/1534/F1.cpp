#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,dp[400005][2],s[400005],a[400005],ans,dfn[400005],low[400005],scc[400005],deg[400005],ti,csc;
char mp[400005];
vector<int> bi[400005];
int id(int x,int y)
{
	return (x-1)*m+y;
}
stack<int> stk;
void tarjan(int x)
{
	stk.push(x);dfn[x]=low[x]=++ti;
	ff(bi[x],it){
		if(!dfn[*it]){
			tarjan(*it);
			low[x]=min(low[x],low[*it]);
		}
		else if(!scc[*it]){
			low[x]=min(low[x],dfn[*it]);
		}
	}
	if(low[x]==dfn[x]){
		csc++;
		while(stk.top()!=x){
			scc[stk.top()]=csc;
			stk.pop();
		}
		scc[stk.top()]=csc;
		stk.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	fz1(i,n)fz1(j,m)cin>>mp[id(i,j)];
	fz1(i,m)cin>>a[i];
	fz1(i,n){
		fz1(j,m){
			if(mp[id(i,j)]=='#'){
				if(s[j]){
					bi[s[j]].push_back(id(i,j));
				}
			}
		}
		fz1(j,m){
			if(mp[id(i,j)]=='#'){
				s[j]=id(i,j);
			}
		}
		fz1(j,m){
			if(mp[id(i,j)]=='#'){
				if(j!=1&&s[j-1]){
					bi[s[j-1]].push_back(id(i,j));
				}
			}
			if(mp[id(i,j)]=='#'){
				if(j!=m&&s[j+1]){
					bi[s[j+1]].push_back(id(i,j));
				}
			}
		}
		if(i!=n)fz1(j,m){
			if(mp[id(i,j)]=='#'){
				if(mp[id(i+1,j)]=='#'){
					bi[id(i+1,j)].push_back(id(i,j));
				}
			}
		}
	}
	fz1(i,n)fz1(j,m)if(mp[id(i,j)]=='#'&&!dfn[id(i,j)]){
		tarjan(id(i,j));
	}
	fz1(i,n)fz1(j,m)if(mp[id(i,j)]=='#'){
		int t=id(i,j);
		ff(bi[t],it) if(scc[t]!=scc[*it]) deg[scc[*it]]=1;
	}
	fz1(i,csc) ans+=!deg[i];
	cout<<ans<<endl;
	return 0;
}