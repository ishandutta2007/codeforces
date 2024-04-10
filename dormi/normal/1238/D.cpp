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
    lli n;
    sc(n);
    string a;
    sc(a);
    lli loc=0;
    lli ans=0;
    lli next=0;
    while(next<n&&a[next]==a[loc])next++;
    while(loc<n){
    	lli oth=next;
    	while(oth<n&&a[oth]==a[loc])oth++;
    	while(loc<oth-1){
    		ans+=n-loc-1-(oth==n?0:1);
    		loc++;
    	}
    	while(oth<n&&a[loc]!=a[oth])oth++;
    	ans+=n-oth;
    	next=oth;
    	loc++;
    }
    prl(ans);
    return 0;
}