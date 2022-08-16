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

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    vc<int> f;
    for(int i=3;i<=n;i++){
    	if(n%i==0)f.pb(i);
    }
    for(int x:f){
    	for(int i=0;i<n/x;i++){
    		int c=1;
    		for(int j=0;j<n;j+=n/x){
    			c*=arr[i+j];
    		}
    		if(c){
    			cout<<"YES";
    			return;
    		}
    	}
    }
    cout<<"NO";
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