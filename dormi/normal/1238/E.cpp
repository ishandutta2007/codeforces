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
int am[20][20];
int dp[(1<<20)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    string a;
    sc(a);
    rep(i,0,sz(a)-1){
    	am[a[i]-'a'][a[i+1]-'a']+=1;
	    am[a[i+1]-'a'][a[i]-'a']+=1;
    }
    rep(i,1,(1<<m)){
    	dp[i]=INT_MAX;//like prefix sum array total contribution that all predertimned characters have, and their subtraction contribution to future characters
    	//runs true dp, cause for every put character it gets that characters total contribution to everything, no matter where future characters go
    	rep(cur,0,m){//end character
    		if(i&(1<<cur)) {
			    int contri=0;//contribution that the character has(if one movement)
			    rep(j, 0, m) {
				    if(cur!=j){
				    	if(i&(1<<j)){//old character add prefixsum, get total end cost
				    		contri+=am[cur][j];
				    	}
				    	else{//new character will be placed evantually, get the contribution of cur character to the new one based off of prefix sum
				    		contri-=am[cur][j];
				    	}
				    }
			    }
			    dp[i]=min(dp[i],dp[i^(1<<cur)]+contri*__builtin_popcount(i));//prefix sum array, cur dist, left index
		    }
    	}
    }
    prl(dp[(1<<m)-1]);
    return 0;
}