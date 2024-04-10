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
    int n;
    sc(n);
    int te=pow(n,2);
    int arr[n][n];
    int x=0,y=0;
    rep(i,1,te+1){
    	arr[x][y]=i;
    	x+=(y%2?-1:1);
    	if(x<0)x=0,y+=1;
    	if(x>=n)x=n-1,y+=1;
    }
    rep(i,0,n){
    	rep(j,0,n){
    		pr(arr[i][j],"");
    	}
    	prl("");
    }
    return 0;
}