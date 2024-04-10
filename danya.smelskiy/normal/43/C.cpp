#include <bits/stdc++.h>
using namespace std;



int n;
int x;
int cnt[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        x%=3;
        ++cnt[x];
    }
    cout<<(cnt[0]/2)+min(cnt[1],cnt[2]);
}