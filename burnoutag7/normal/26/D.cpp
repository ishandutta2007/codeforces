#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;
long double ans=1;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=m;i>=m-k;i--)ans*=i;
    for(int i=n+1;i<=n+k+1;i++)ans/=i;
    cout<<max(1-ans,(long double)0)<<endl;

    return 0;
}