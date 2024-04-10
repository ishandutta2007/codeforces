#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n,x;int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int ans=0;long long sm=0;
        for(int i=n;i>=1;i--){
            sm+=a[i];
            if(sm>=(long long)x*(n-i+1))ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}