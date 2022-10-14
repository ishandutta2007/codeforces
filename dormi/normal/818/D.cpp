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
const int MAXC=1e6+1;
int am[MAXC];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,A;
    sc(n,A);
    int Aam=0;
    set<pii> ams;
    rep(i,1,(int)MAXC){
    	if(i!=A)ams.insert({0,i});
    }
    int in;
    rep(i,0,n){
    	sc(in);
    	if(in==A){
    		am[A]++;
    		while(sz(ams)&&ams.begin()->first<am[A]){
    			ams.erase(ams.begin());
    		}
    	}
    	else if(ams.count({am[in],in})){
    		ams.erase({am[in],in});
    		am[in]++;
    		ams.insert({am[in],in});
    	}
    }
    if(sz(ams)){
    	prl(ams.begin()->second);
    }
    else prl(-1);
    return 0;
}