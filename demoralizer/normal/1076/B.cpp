#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,t=0;
    cin>>n;
    if(n%2==0){cout<<(n/2);return 0;}
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){n-=i;t++;break;}
    }
    if(n%2==0){cout<<(t+n/2);return 0;}
    cout<<"1";
}