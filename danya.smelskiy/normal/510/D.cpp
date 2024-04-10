#include <bits/stdc++.h>
using namespace std;

set<int> s;
map<int,int> ans;
pair<int,int> a[10005];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first;
    for (int i=1;i<=n;++i)
        cin>>a[i].second;
    s.insert(0);
    for (int i=1;i<=n;++i) {
        set<int> ::iterator q=s.begin();
        while (q!=s.end()) {
            int x=*q;
            ++q;
            int y=__gcd(x,a[i].first);
            if (s.find(y)!=s.end()) {
                ans[y]=min(ans[y],ans[x]+a[i].second);
            } else {
                ans[y]=ans[x]+a[i].second;
                s.insert(y);
            }
        }
    }
    if (ans[1]==0) cout<<"-1";
    else cout<<ans[1];
}