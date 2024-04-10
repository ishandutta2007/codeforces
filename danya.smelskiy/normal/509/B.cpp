#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[105];
int mn=1e9;
int mx;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    for (int i=1;i<=n;++i)
        mx=max(mx,a[i]-mn);
    if (mx>k) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=min(mn+1,a[i]);++j)
            cout<<"1 ";
        int last=2;
        for (int j=1;j<=a[i]-mn-1;++j) {
            cout<<last++<<" ";
        }
        cout<<'\n';
    }
}