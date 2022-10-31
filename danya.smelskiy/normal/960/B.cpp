#include <bits/stdc++.h>
using namespace std;






int n,k1,k2;
int a[1005];
int b[1005];
set<pair<long long,int> > s;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k1>>k2;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i) {
        s.insert(make_pair(-abs(a[i]-b[i]),i));
    }
    while (k1--) {
        int x=s.begin()->second;
        s.erase(s.begin());
        if (a[x]>b[x]) {
            --a[x];
        } else ++a[x];
        s.insert(make_pair(-abs(a[x]-b[x]),x));
    }
    while (k2--) {
        int x=s.begin()->second;
        s.erase(s.begin());
        if (b[x]>a[x]) {
            --b[x];
        } else ++b[x];
        s.insert(make_pair(-abs(a[x]-b[x]),x));
    }
    long long ans=0;
    for (int i=1;i<=n;++i) {
        long long x=(a[i]-b[i]);
        ans+=x*x;
    }
    cout<<ans;
}