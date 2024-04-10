#include <bits/stdc++.h>
using namespace std;


int n;
int a[100005];
multiset<int> s;
int x;
int ans;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        s.insert(a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        x=a[i];
        multiset<int> :: iterator q=s.upper_bound(x);
        if (q==s.end()) --q;
        if (*q>x) ++ans;
        s.erase(q);
    }
    cout<<ans;
}