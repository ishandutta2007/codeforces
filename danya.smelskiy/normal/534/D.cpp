#include <bits/stdc++.h>
using namespace std;


int n;
int sz;
int ans[200005];
vector<int> v[200005];
int cnt[200005];


inline void f(int x) {
    int y=v[x][cnt[x]];
    ans[++sz]=y;
    ++cnt[x];
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    if (v[0].size()==0) {
        cout<<"Impossible";
        return 0;
    }
    f(0);
    int last=1;
    while (sz<n) {
        bool t=false;
        while (last>=0) {
            if (cnt[last]==v[last].size()) {
                last-=3;
                continue;
            }
            f(last);
            t=true;
            ++last;
            break;
        }
        if (!t) {
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible"<<'\n';
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}