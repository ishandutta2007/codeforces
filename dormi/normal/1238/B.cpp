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
	int q;
	sc(q);
	while(q--){
		int n;
		lli r;
		sc(n,r);
		vector<lli> arr;
		lli in;
		rep(i,0,n){
			sc(in);
			arr.push_back(in);
		}
		sort(arr.begin(),arr.end());
		lli am=0;
		rep(i,n,0){
			if(i!=n-1&&arr[i]==arr[i+1])continue;
			if(arr[i]-am*r<=0)break;
			else{
				am+=1;
			}
		}
		prl(am);
	}
    return 0;
}