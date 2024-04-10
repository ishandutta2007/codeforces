#include <bits/stdc++.h>
using namespace std;


int n;
int a[5005];
map<vector<int>,int> used;
int num[5005];
int all;
int ans[5005];
int cnt[5005];
vector<int> v[5005];


inline vector<int> get(int x) {
    bool t=false;
    if (x<0) {
        t=true;
        x=-x;
    }
    vector<int> res;
    res.clear();
    int c=0;
    for (int i=2;i*i<=x;++i) if (x%i==0) {
        c=0;
        while (x%i==0) {
            x/=i;
            ++c;
        }
        if (c&1) res.push_back(i);
    }
    if (x>1) res.push_back(x);
    sort(res.begin(),res.end());
    if (t) {
        if (res.size()==0) res.push_back(-1);
        else res[0]=-res[0];
    } else {
        if (res.size()==0) res.push_back(0);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]!=0)
        v[i]=get(a[i]);
        if (a[i]!=0) {
            if (!used[v[i]]) {
                used[v[i]]=++all;
            }
        }
        num[i]=used[v[i]];
    }
    for (int i=1;i<=n;++i) {
        bool t=false;
        for (int j=1;j<=all;++j)
            cnt[j]=0;
        int nw=0;
        for (int j=i;j<=n;++j) {
            if (a[j]==0) {}
            else {
                ++cnt[num[j]];
                if (cnt[num[j]]==1) ++nw;
            }
            if(!nw) ++ans[1]; else
            ++ans[nw];
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";

}