#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>

int second(int k,int x,int b){
	return (k*x+b);
}
void solve(){
    int k,b,n,t;
    cin>>k>>b>>n>>t;
    int x,c=0;
    x=1;
    while(x<t){
    	c++;
    	x=second(k,x,b);
    }
    if(x>t)c--;
    cout<<max(0LL,n-c);
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}