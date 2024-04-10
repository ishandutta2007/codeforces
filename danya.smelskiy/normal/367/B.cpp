#include <bits/stdc++.h>
using namespace std;


int n,m,k;
int a[200005];
int b[200005];
int nw1;
map<int,int> cnt1,cnt2;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=m;++i)
        cin>>a[i];
    swap(n,m);
    for (int i=1;i<=n;++i) {
        ++cnt1[a[i]];
        if (cnt1[a[i]]==1) ++nw1;
    }
    for (int i=1;i<=min(m,k);++i) {
        vector<int> v;
        for (int j=i;j<=m;j+=k)
            v.push_back(b[j]);
        cnt2.clear();
        int l=0;
        int nw=0;
        if (v.size()<n) continue;
        for (int j=0;j<v.size();++j) {
            ++cnt2[v[j]];
            if (cnt2[v[j]]==cnt1[v[j]]) ++nw;
            else if (cnt2[v[j]]==cnt1[v[j]]+1) --nw;
            while (j-l+1>n) {
                int x=v[l++];
                if (cnt2[x]==cnt1[x]) --nw;
                --cnt2[x];
                if (cnt2[x]==cnt1[x]) ++nw;
            }
            if (nw==nw1) {
                int x=i+l*k;
                ans.push_back(x);
            }
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for (auto it : ans)
        cout<<it<<" ";
}