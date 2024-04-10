#include <bits/stdc++.h>
using namespace std;


int n,a;
int cnt[1000005];
int cnta;
set<pair<int,int> > s;
bool used[1000005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    for (int i=1;i<=1e6;++i)
    if (i!=a)
        s.insert(make_pair(0,i));
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (x==a) {
            ++cnta;
            while (!s.empty()) {
                int x=s.begin()->second;
                if (cnt[x]<cnta) {
                    s.erase(s.begin());
                    used[x]=true;
                    continue;
                } else break;
            }
        } else if (used[x]==false) {
            s.erase(make_pair(cnt[x],x));
            ++cnt[x];
            s.insert(make_pair(cnt[x],x));
        }
    }
    for (int i=1;i<=1e6;++i)
    if (used[i]==false && i!=a) {
        cout<<i;
        return 0;
    }
    cout<<"-1";
}