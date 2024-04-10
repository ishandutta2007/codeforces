#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5;
int n,m; ll l,r;
vector<int> s[N];
struct K{
	int x,y;
};
inline bool operator<(K a,K b){ return a.x<b.x||a.x==b.x&&a.y<b.y; }
set<K> ss;
int main(){
	scanf("%d%d%lld%lld",&n,&m,&l,&r);
	int cnt=0;
	for(int i=1;i<=max(n,m);++i)
		for(int j=1;i*j<=max(n,m);++j)
			s[i*j].push_back(i);
	int lp=1,rp=0;
	vector<vector<int> > ans;
	for(int x1=n;x1>=1;--x1){
		while(rp+1<=m&&1ll*x1*(rp+1)<=r){
			++rp;
			for(auto t:s[rp])
				if(t<=n)
					ss.insert((K){t,rp});
		}
		bool flag=0;
		for(auto t:s[x1]){
			auto it=ss.lower_bound((K){t+1,0});
			while(it!=ss.end()&&1ll*x1*it->y<l) {
				auto it1=next(it);
				ss.erase(it);
				it=it1;
			}
//			assert(it==ss.end()||1ll*it->y*x1>=l);
			if(it!=ss.end()&&1ll*x1/t*it->x<=n){
				ans.push_back(vector<int>({x1,it->y
					,x1/t*it->x,it->y/it->x*t}));
				flag=1;
				break;
			}
		}
		if(!flag) ans.push_back(vector<int>({-1}));
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans){
		for(auto y:x)
			printf("%d ",y);
		puts("");
	}
	return 0;
}