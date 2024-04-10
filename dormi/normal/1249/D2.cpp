#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,k;
	sc(n,k);
	set<pair<pll,int>> segs;
	int l=0,r=-1;
	pair<pii,int> arr[n];
	rep(i,0,n){
		sc(arr[i].first.first,arr[i].first.second);
		arr[i].second=i+1;
	}
	sort(arr,arr+n);
	int loc=0;
	vector<int> inds;
	rep(i,1,2e5+1){
		while(sz(segs)&&segs.begin()->first.first<i)segs.erase(segs.begin());
		while(loc<n&&arr[loc].first.first<=i){
			segs.insert({{arr[loc].first.second,arr[loc].first.first},arr[loc].second});
			loc++;
		}
		while(sz(segs)>k){
			inds.push_back(segs.rbegin()->second);
			segs.erase(prev(segs.end(),1));
		}
	}
	prl(sz(inds));
	for(int x:inds)pr(x,"");
    return 0;
}