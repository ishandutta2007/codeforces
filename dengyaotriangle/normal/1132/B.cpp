#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n,m;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    long long sm=0;
    for(int i=1;i<=n;i++) sm+=a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        cout<<sm-a[t]<<'\n';
    }
    return 0;
}