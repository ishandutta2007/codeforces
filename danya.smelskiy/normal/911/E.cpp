#include <bits/stdc++.h>
using namespace std;

int n,m;
set<int> s;
int r[200005];
vector<int> ans;

inline void add(int x,int y) {
    if (x>y) return;
    s.insert(x);
    r[x]=y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    r[1]=n;
    s.insert(1);
    for (int i=1;i<=m;++i) {
        int x;
        cin>>x;
        ans.push_back(x);
        int ll=*s.begin();
        if (x<ll || x>r[ll]) {
            cout<<"-1";
            return 0;
        }
        s.erase(s.begin());
        int rr=r[ll];
        add(ll,x-1);
        add(x+1,rr);
    }
    while (!s.empty()) {
        int x=*s.begin();
        s.erase(s.begin());
        int y=r[x];
        while (y>=x) {
            ans.push_back(y);
            --y;
        }
    }
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}