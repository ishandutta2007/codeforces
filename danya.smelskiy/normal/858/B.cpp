#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000];
int b[1000];
bool used[1000];
int all;
vector<int> qq;

inline bool f(int x){
    for (int i=1;i<=m;++i) {
        if ((a[i]+x-1)/x!=b[i]) return false;
    }
    qq.push_back((n+x-1)/x);
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) {
        cout<<1;
        return 0;
    }
    cin>>m;
    if (m==0) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=m;++i) {
        cin>>a[i]>>b[i];
        if (a[i]==n) {
            cout<<b[i];
            return 0;
        }
    }
    for (int i=1;i<=m;++i)
    for (int j=1;j<=m;++j) {
        if (a[i]>=n && a[j]<=n && b[i]==b[j]) {
            cout<<b[i];
            return 0;
        }
    }
    int ans=0;
    int kol=0;
    for (int i=1;i<=1000;++i) if (f(i)) {
        ++kol;
        ans=(i+n-1)/i;
    }
    for (int i=1;i<qq.size();++i) {
        if (qq[i]!=qq[i-1]) {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;
}