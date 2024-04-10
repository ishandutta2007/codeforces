#include <bits/stdc++.h>
using namespace std;




int n,m;
vector<pair<int,int> > ans;
bool pr[100005];


inline void solve(int x) {
    for (int i=x+1;i<=n && m>0;++i)
    if (__gcd(i,x)==1) {
        --m;
        ans.push_back(make_pair(x,i));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m<n-1) {
        cout<<"Impossible";
        return 0;
    }
    for (int i=2;i<=n;++i) {
        --m;
        ans.push_back(make_pair(1,i));
    }
    for (int i=2;i*i<=n;++i)
    if (pr[i]==false) {
        for (int j=i*i;j<=n;j+=i)
            pr[j]=true;
    }
    for (int i=2;i<=n;++i)
        if (pr[i]==false) solve(i);
    for (int i=2;i<=n;++i)
        if (pr[i]) solve(i);
    if (m) {
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible"<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}