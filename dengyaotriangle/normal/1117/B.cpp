#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
long long m,k;
int a[maxn];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    long long tm=m/(k+1);
    long long ans=tm*(a[1]*k+a[2]);
    ans+=(m-tm*(k+1))*a[1];
    cout<<ans;
    return 0;
}