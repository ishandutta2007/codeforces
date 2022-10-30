#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[1005];
set<pair<int,int> > s;
int ans[1005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>a[i];
        s.insert(make_pair(-a[i],i));
    }
    for (int i=1;i<=n;++i) {
        set<pair<int,int> > :: iterator q=s.begin();
        while (true) {
            if (q==s.end()) {
                cout<<"-1";
                return 0;
            }
            int x=q->first;
            int y=q->second;
            x=-x;
            if ((i==1 || y!=ans[i-1]) && (i<n || ans[1]!=y)) {
                if (i>1 && ans[1]!=y && a[ans[1]]==a[y] && ans[1]!=ans[i-1] && i<n) {
                    ++q;
                    continue;
                }
                ans[i]=y;
                s.erase(q);
                --a[y];
                if (a[y]) s.insert(make_pair(-a[y],y));
                break;
            } else ++q;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}