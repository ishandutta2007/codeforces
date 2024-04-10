#include <bits/stdc++.h>
using namespace std;
int n;
multiset<int> s1,s2;
long long ans;
int a[300005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    s1.insert(1e9);
    s2.insert(1e9);
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        int x=*s1.begin();
        int y=*s2.begin();
        if (a[i]-x<0 && a[i]-y<0) s1.insert(a[i]);
        else {
            if (a[i]-x>a[i]-y) {
                s1.erase(s1.begin());
                s2.insert(a[i]);
                ans+=(long long)(a[i]-x);
            } else {
                s2.erase(s2.begin());
                ans+=a[i]-y;
                s1.insert(y);
                s2.insert(a[i]);
            }
        }
    }
    cout<<ans;
}