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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    map<int,vector<lli>> ma;
    lli in;
    rep(i,0,n){
    	sc(in);
    	lli og=in;
    	int cnt=0;
    	while(in%2==0)in/=2,cnt++;
    	ma[cnt].push_back(og);
    }
    pii ans={0,0};
    for(auto x:ma){
    	if((int)x.second.size()>ans.second)ans={x.first,x.second.size()};
    }
    prl(n-ans.second);
    for(auto x:ma){
    	if(x.first!=ans.first){
    		for(auto y:x.second)pr(y,"");
    	}
    }
    return 0;
}