#include <bits/stdc++.h>
using namespace std;
int n;
int kol[200005];
int ans;
set<int> s;
int a[200005];
bool used[200005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ++kol[a[i]];
        if (kol[a[i]]!=1) ++ans;
    }
    for (int i=1;i<=n;++i)
        if (!kol[i]) s.insert(i);
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i) {
        if (kol[a[i]]==1 && used[a[i]]) {
            int x=*s.begin();
            s.erase(s.begin());
            cout<<x<<" ";
        } else if (kol[a[i]]==1) {
            cout<<a[i]<<" ";
        } else {
            int x=*s.begin();
            if (used[a[i]]) {
                s.erase(s.begin());
                cout<<x<<" ";
                --kol[a[i]];
            } else if (x<a[i]) {
                --kol[a[i]];
                s.erase(s.begin());
                cout<<x<<" ";
            } else {
                used[a[i]]=true;
                cout<<a[i]<<" ";
                --kol[a[i]];
            }
        }
    }
}