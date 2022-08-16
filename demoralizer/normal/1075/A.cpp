#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,x,y;
    cin>>n>>x>>y;
    ll a=max(x-1,y-1);
    ll b=max(n-x,n-y);
    if(a<=b)cout<<"White";
    else cout<<"Black";
}