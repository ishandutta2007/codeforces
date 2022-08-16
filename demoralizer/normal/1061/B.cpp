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
    ll n,m,s=0,t=0,h=0;
    cin>>n>>m;
    ll a[n+1];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        t+=a[i];
    }
    sort(a,a+n);
    a[n]=0;
    for(ll i=0;i<n;i++){
        if(a[i]>h)h++;
        s++;
    }
    s+=a[n-1]-h;
    cout<<(t-s);
}