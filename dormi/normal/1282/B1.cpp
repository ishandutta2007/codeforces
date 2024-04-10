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
lli cost[(int)2e5+1];
int n,k;
lli p;
bool work(int am){
	lli te=0;
	int lasti=am+k-1;
	for(int i=am-1;i>=k-1;i-=k){
		te+=cost[i];
		lasti=i;
	}
	for(int i=0;i<=lasti-k;i++)te+=cost[i];
	return te<=p;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int t;
	sc(t);
	while(t--){
		sc(n,p,k);
		rep(i,0,n){
			sc(cost[i]);
		}
		sort(cost,cost+n);
		int lo=0;
		int hi=n/k;
		while(lo!=hi){
			int mid=(lo+hi)/2+1;
			if(work(mid*k))lo=mid;
			else hi=mid-1;
		}
		lo*=k;
		for(;lo<n;lo++)if(!work(lo+1))break;
		prl(lo);
	}
    return 0;
}