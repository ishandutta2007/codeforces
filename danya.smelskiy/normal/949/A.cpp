#include <bits/stdc++.h>
using namespace std;

string s;
int n;
set<int> s1,s2;
int all;
vector<int> ans[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    s="#"+s;
    n=s.size()-1;
    int x;
    for (int i=1;i<=n;++i) {
        int x=s[i]-'0';
        if (x==0) {
            if (!s2.empty()) {
                x=*s2.begin();
                s2.erase(s2.begin());
                ans[x].push_back(i);
                s1.insert(x);
            } else {
                ++all;
                s1.insert(all);
                ans[all].push_back(i);
            }
        } else {
            if (s1.empty()) {
                cout<<"-1";
                return 0;
            } else {
                x=*s1.begin();
                ans[x].push_back(i);
                s1.erase(s1.begin());
                s2.insert(x);
            }
        }
    }
    if (!s2.empty()) {
        cout<<"-1";
        return 0;
    }
    cout<<all<<'\n';
    for (int i=1;i<=all;++i) {
        cout<<ans[i].size()<<" ";
        for (int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}