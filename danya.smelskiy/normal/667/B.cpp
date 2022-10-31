#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    int res=a[n];
    for (int i=1;i<n;++i)
        res-=a[i];
    cout<<res+1;
}