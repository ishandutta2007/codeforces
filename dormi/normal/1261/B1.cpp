#include<bits/stdc++.h>
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
const int MAXN=2e5+1;
int bit[MAXN];
int n;
void update(int loc){
	for(;loc<=n;loc+=loc&-loc)bit[loc]+=1;
}
int query(int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
	return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n);
    vector<pii> arr;
    int in;
    int arr2[n+1];
    rep(i,1,n+1){
		sc(in);
		arr2[i]=in;
		arr.push_back({in,-i});
    }
    sort(arr.begin(),arr.end(),greater<pii>());
    int m;
    sc(m);
    vector<pair<int,pii>> queries;
    int a,b;
    int ans[m];
    rep(i,0,m){
    	sc(a,b);
    	queries.push_back({a,{b,i}});
    }
    sort(queries.begin(),queries.end());
    int loc=0;
    rep(i,0,n){
    	update(-arr[i].second);
    	while(loc<m&&queries[loc].first==i+1){
    		int lo=1;
    		int hi=n;
    		while(lo!=hi){
    			int mid=(lo+hi)/2;
    			if(query(mid)>=queries[loc].second.first)hi=mid;
    			else lo=mid+1;
    		}
    		ans[queries[loc].second.second]=arr2[lo];
    		loc++;
    	}
    }
    rep(i,0,m){
    	prl(ans[i]);
    }
    return 0;
}