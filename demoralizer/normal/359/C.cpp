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

int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
mii m;
void solve(){
    int n,x,mx=0,sum=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
    	int t;cin>>t;
    	sum+=t;
    	m[t]++;
    	mx=max(mx,t);
    }
    int i;
    for(i=mx;i>0;i--){
    	m[i-1]+=m[i]/x;
    	m[i]%=x;
    	if(m[i]){break;}
    }
    cout<<pw(x,sum-i,M);
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