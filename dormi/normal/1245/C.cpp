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
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    sc(s);
    vector<lli> th;
    char last='^';
    lli dp[sz(s)+1];
    dp[0]=1;
    int loc=1;
    for(char x:s){
    	if(x=='m'||x=='w'){
    		prl(0);
    		return 0;
    	}
    	dp[loc]=dp[loc-1];
    	if(last=='u'||last=='n'){
    		if(x==last){
    			dp[loc]=(dp[loc-2]+dp[loc])%mod;
    		}
    	}
    	last=x;
    	loc++;
    }
    prl(dp[sz(s)]);
    return 0;
}