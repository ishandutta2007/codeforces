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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,a[200005];
vector<int> pos[200005];
vector<int> ans;
void solve()
{
	read(n);fz1(i,n)read(a[i]);ans.clear();
	fz0g(i,n) pos[i].clear();fz1(i,n)pos[a[i]].push_back(i);
	fz0g(i,n) reverse(pos[i].begin(),pos[i].end());
	int tmp=n+1,p=1;
	fz0g(i,n) if(pos[i].empty()) tmp=min(tmp,i);
	while(p<=n){
		if(tmp==0){
			ans.push_back(0);
			p++;continue;
		}
		fz0g(i,tmp-1){
			while(pos[i].size()&&pos[i].back()<p) pos[i].pop_back();
			if(pos[i].empty()) tmp=min(tmp,i);
		}
		if(tmp==0){
			ans.push_back(0);
			p++;continue;
		}
		int nxt=p;
		fz0g(i,tmp-1) nxt=max(nxt,pos[i].back());
		p=nxt+1;ans.push_back(tmp);
	}
	printf("%d\n",ans.size());
	ff(ans,it) printf("%d ",*it);puts("");
}
int main()
{
	read(t);while(t--)solve();
	return 0;
}