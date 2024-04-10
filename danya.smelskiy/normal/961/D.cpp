#include <bits/stdc++.h>
using namespace std;


int n;
pair<long long,long long> a[100005];
bool used[100005];



inline bool on_line(pair<long long,long long> x,pair<long long,long long> y,pair<long long,long long> z) {
    long long res=x.first*(y.second-z.second)+y.first*(z.second-x.second)+z.first*(x.second-y.second);
    if (res==0) return true;
    swap(x,y);
    res=x.first*(y.second-z.second)+y.first*(z.second-x.second)+z.first*(x.second-y.second);
    if (res==0) return true;
    swap(y,z);
    res=x.first*(y.second-z.second)+y.first*(z.second-x.second)+z.first*(x.second-y.second);
    if (res==0) return true;
    swap(x,y);
    res=x.first*(y.second-z.second)+y.first*(z.second-x.second)+z.first*(x.second-y.second);
    if (res==0) return true;
    return false;
}

inline bool check(vector<int> v) {
    for (int i=2;i<v.size();++i)
        if (!on_line(a[v[i-2]],a[v[i-1]],a[v[i]])) return false;
    return true;
}

map<long long,int> cnt;


inline void solve() {
    vector<int> v;
    for (int i=3;i<=n;++i)
        if (!on_line(a[1],a[2],a[i])) v.push_back(i);
    if (check(v)) {
        cout<<"YES";
        exit(0);
    }
    cnt.clear();
    int pos=-1;
    for (int i=2;i<=n;++i) {
        long long C;
        if (a[i].first==a[1].first) {
            C=-228;
        } else {
            C=(a[i].second-a[1].second)/(a[i].first-a[1].first);
        }
        ++cnt[C];
        if (cnt[C]==2) {
            pos=i;
            break;
        }
    }
    if (pos==-1) return;
    v.clear();
    for (int i=2;i<=n;++i)
        if (i!=pos && !on_line(a[1],a[pos],a[i])) v.push_back(i);
    if (check(v)) {
        cout<<"YES";
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    if (n<=4) {
        cout<<"YES";
        return 0;
    }
    solve();
    swap(a[1],a[2]);
    solve();
    cout<<"NO";
}