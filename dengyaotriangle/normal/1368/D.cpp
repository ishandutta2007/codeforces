#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
int a[maxn];
int b[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=0;j<21;j++){
        int c0=0;
        for(int i=1;i<=n;i++)c0+=((a[i]>>j)&1);
        for(int i=1;i<=n;i++)b[i]|=((--c0)>=0)<<j;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)ans+=b[i]*(long long)b[i];
    cout<<ans;
    return 0;
}