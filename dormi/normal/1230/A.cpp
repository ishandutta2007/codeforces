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
    int arr[4];
    rep(i,0,4)sc(arr[i]);
    rep(i,0,(1<<4)){
    	int a=0,b=0;
    	rep(j,0,4){
    		if(i&(1<<j)){
    			a+=arr[j];
    		}
    		else b+=arr[j];
    	}
    	if(a==b){
    		prl("YES");
    		return 0;
    	}
    }
    prl("NO");
    return 0;
}