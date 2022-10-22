#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e4+10;
int T,n,ans[N];bool vis[N];
signed main(){
	read(T);while(T--){
		read(n);vector<int>now;
		for(int i=1,p;i<=n;i++)read(p),now.pb(p);
		reverse(now.begin(),now.end());
		for(int cnt=1;now.size();cnt++){
			set<int>s;
			for(auto x:now)vis[x]=0,s.insert(x);
			for(auto x:now)if(!vis[x]){
				auto it=s.find(x);ans[x]=cnt;
				if(it!=s.begin())it--,vis[*it]=1,it++;
				it++;if(it!=s.end())vis[*it]=1;it--;
				s.erase(it);
			}else s.erase(x);
			vector<int>nw;
			for(auto x:now)if(vis[x])nw.pb(x);
			swap(now,nw);
		}
		for(int i=1;i<=n;i++)write(ans[i]),pc(' ');pc('\n');
	}
}