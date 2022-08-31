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
    string arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    vc<pii> p,q;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(arr[i][j]=='.'){
    			p.pb({i,j});
    			break;
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(arr[j][i]=='.'){
    			q.pb({j,i});
    			break;
    		}
    	}
    }
    if(p.size()==n){
    	for(auto x:p){
    		cout<<x.fr+1<<" "<<x.sc+1<<"\n";
    	}
    }
    else if(q.size()==n){
    	for(auto x:q){
    		cout<<x.fr+1<<" "<<x.sc+1<<"\n";
    	}
    }
    else{
    	cout<<-1;
    }
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