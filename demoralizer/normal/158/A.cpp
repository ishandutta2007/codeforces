#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<ll,ll>
#define msi map<string,ll>
#define mii map<ll,ll>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int u=a[k-1],c=0;
    for(int i=0;i<n;i++){
        if(a[i]>=u&&a[i]>0)c++;
    }
    cout<<c;
}