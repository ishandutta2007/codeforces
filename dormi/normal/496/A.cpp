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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	int arr[n];
	int ma=0;
	rep(i,0,n){
		sc(arr[i]);
		if(i>0)ma=max(arr[i]-arr[i-1],ma);
	}
	int mi2=INT_MAX;
	rep(i,1,n-1){
		mi2=min(arr[i+1]-arr[i-1],mi2);
	}
	prl(max(ma,mi2));
    return 0;
}