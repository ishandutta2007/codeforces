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
    int n,mx;
    cin>>n;
    for(int i=0;i<n;i++){
    	int t;cin>>t;
    	if(i==0)mx=t;
    	mx=min(t,mx);
    }
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    sort(arr,arr+n,greater<int>());
    int cost=0,k=0;
    for(int i=0;i<n;i++){
    	k++;
    	cost+=arr[i];
    	if(k==mx){
    		k=0;
    		i+=2;
    	}
    }
    cout<<cost;
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