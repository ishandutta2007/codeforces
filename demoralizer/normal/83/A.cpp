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
    ll n,c=1,s,t,k=0;
    cin>>n>>s;
    for(int i=1;i<n;i++){
        cin>>t;
        if(t==s)c++;
        else{
            k+=c*(c+1)/2;
            c=1;
        }
        s=t;
    }
    k+=c*(c+1)/2;
    cout<<k;
}