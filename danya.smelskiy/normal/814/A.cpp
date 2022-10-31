#include <bits/stdc++.h>
using namespace std;
int n,m;
int t;
int a[100001];
int b[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m>=2) {
        cout<<"Yes";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]==0 && a[i-1]==0 && i>1) ++t;
    }
    for (int i=1;i<=m;++i) {
        cin>>b[i];
    }
    sort(b+1,b+m+1);
    if (t && m>1) {
        cout<<"Yes";
        return 0;
    }
    int mx=0;
    int mn=1e9;
    for (int i=1;i<=n;++i) {
        mx=max(mx,a[i]);
        if (a[i]!=0 && a[i]<mx) {
            cout<<"Yes";
            return 0;
        }
        if (a[i]==0 && mx>b[1]) {
            cout<<"Yes";
            return 0;
        }
    }
    for (int i=n;i>0;--i) {
        if (a[i]!=0) mn=min(mn,a[i]);
        if (a[i]!=0 && mn<a[i]) {
            cout<<"Yes";
            return 0;
        }
        if (a[i]==0 && mn<b[m]) {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}