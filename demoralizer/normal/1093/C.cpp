#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define psi pair<string,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m;
    cin>>m;n=m/2;
    ll b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll a[2*n],j=0,k=b[0]+1;
    for(int i=0;i<n;i++){
        if((b[i]-j)>=k){
            a[2*n-1-i]=k;
            a[i]=b[i]-k;
            j=a[i];
        }
        else{
            a[i]=j;
            a[2*n-1-i]=b[i]-j;
            k=b[i]-j;
        }
    }
    for(int i=0;i<2*n;i++)cout<<a[i]<<" ";
}