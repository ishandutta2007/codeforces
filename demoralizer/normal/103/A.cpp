#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,t,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        c+=t+i*(t-1);
    }
    cout<<c;
}