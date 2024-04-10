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
bool work(int c,int m,int x,int lo){
	if(lo>m||lo>c)return false;
	if(x+m-lo+c-lo>=lo)return true;
	return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    sc(q);
    while(q--){
    	int c,m,x;
    	sc(c,m,x);
    	if(x>=min(c,m)){
    		prl(min(c,m));
    	}
    	else{
    		int lo=0;
    		int hi=1e8;
    		while(lo!=hi){
    			int mid=(lo+hi)/2+1;
    			if(work(c,m,x,mid))lo=mid;
    			else hi=mid-1;
    		}
    		prl(lo);
    	}
    }
    return 0;
}