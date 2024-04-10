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
const int MAXN=2e5+1;
lli prefix[MAXN];
lli sketch[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    int arr[m];
    rep(i,0,m)sc(arr[i]);
    lli tot=0;
    rep(i,0,m-1){
    	if(arr[i]!=arr[i+1]) {
		    prefix[min(arr[i], arr[i + 1])] += 1;
		    prefix[max(arr[i], arr[i + 1])] -= 1;
		    tot += abs(arr[i + 1] - arr[i]);
		    sketch[arr[i]] += arr[i + 1] - abs(arr[i + 1] - arr[i]);
		    sketch[arr[i + 1]] += arr[i] - abs(arr[i + 1] - arr[i]);
	    }
    }
    rep(i,1,n+1)prefix[i]+=prefix[i-1];
    rep(i,1,n+1)pr(tot+sketch[i]-prefix[i],"");
    return 0;
}