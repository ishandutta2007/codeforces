#include <bits/stdc++.h>
using namespace std;


int n,m;
int cnt_open;
int cnt[1005];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x;
        cin>>x;
        ++cnt[x];
        if (cnt[x]==1) {
            ++cnt_open;
        }
        if (cnt_open==n) {
            for (int i=1;i<=n;++i) {
                --cnt[i];
                if (cnt[i]==0) --cnt_open;
            }
            ++ans;
        }
    }
    cout<<ans;
}