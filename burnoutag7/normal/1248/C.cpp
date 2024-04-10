#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int n,m;
int f[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    f[1]=2;
    for(int i=2;i<=1e5;i++)
        f[i]=(f[i-1]+f[i-2])%mod;
    cin>>n>>m;
    cout<<((long long)f[n-1]+f[n]+f[m-1]+f[m]-2)%mod<<endl;

    return 0;
}