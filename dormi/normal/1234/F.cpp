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
int maxbitcnt[(1<<20)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    sc(a);
    rep(i,0,sz(a)){
    	int cur=0;
		rep(j,0,20){
			if(i+j==sz(a))break;
			if(cur&(1<<(a[i+j]-'a')))break;
			cur+=(1<<(a[i+j]-'a'));
			maxbitcnt[cur]=j+1;
		}
    }
    rep(i,0,20){
    	rep(j,0,(1<<20)){
    		if(j&(1<<i))maxbitcnt[j]=max(maxbitcnt[j],maxbitcnt[j^(1<<i)]);
    	}
    }
    int ans=0;
    rep(i,0,(1<<20)){
    	ans=max(ans,maxbitcnt[i]+maxbitcnt[((1<<20)-1)^i]);
    }
    prl(ans);
    return 0;
}