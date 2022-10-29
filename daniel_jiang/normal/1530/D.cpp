// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=2e5+5;
int T,n,a[N],ans[N],ans1,deg[N];
vector<int> b[N];
set<int> S;
set<int>::iterator it;

inline bool cmp(int x,int y){return deg[x]<deg[y];}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);ans1=0;
		for(re i=1;i<=n;++i){
			rd(a[i]);
			b[a[i]].pb(i);++deg[a[i]];ans[i]=0;S.insert(i);
		}
		for(re i=1;i<=n;++i)
			if(b[i].size()){
				sort(b[i].begin(),b[i].end(),cmp);
				ans[b[i][0]]=i;++ans1;S.erase(i);
			}
		vector<int> res;
		for(re i=1;i<=n;++i)
			if(!ans[i]&&S.count(i)) res.pb(i),S.erase(i);
		if(res.size()==1){
			it=S.begin();
			ans[res[0]]=(*it);S.erase(it);S.insert(res[0]);
		}
		else{
			for(re i=0;i<res.size();++i)
				ans[res[i]]=res[(i+1)%res.size()];
		}
		for(re i=1;i<=n;++i)
			if(!ans[i]){
				it=S.begin();
				if((*it)==i) ++it;ans[i]=(*it);
				S.erase(it); 
			}
		wr(ans1);puts("");
		for(re i=1;i<=n;++i) wr(ans[i]),putchar(' '),deg[i]=0,b[i].clear();
		puts("");
	}
	return 0;
}

// ---------- Main ---------- //