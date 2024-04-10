#include <bits/stdc++.h>
using namespace std;




int n,x1,x2;
pair<int,int> a[300005];
bool dp1[300005];
bool dp2[300005];
bool dp3[300005];
bool dp4[300005];
int nxt1[300005];
int nxt2[300005];

inline void solve(int x1,int x2,int z1) {
    int x;
    for (int i=n;i>0;--i) {
        dp1[i]=dp2[i]=dp3[i]=dp4[i]=false;
        x=(x1+a[i].first-1)/a[i].first;
        if (i+x-1<=n) dp1[i]=true,nxt1[i]=i+x;
        x=(x2+a[i].first-1)/a[i].first;
        if (i+x-1<=n) dp3[i]=true,nxt2[i]=i+x;
        dp2[i]=(dp1[i]|dp2[i+1]);
        dp4[i]=(dp3[i]|dp4[i+1]);
    }
    for (int i=1;i<=n;++i) {
        if (dp1[i] && dp4[nxt1[i]]) {
            cout<<"Yes"<<'\n';
            vector<int> v1,v2;
            v1.clear(); v2.clear();
            for (int j=i;j<nxt1[i];++j)
                v1.push_back(a[j].second);
            for (int j=nxt1[i];j<=n;++j)
            if (dp3[j]) {
                for (int k=j;k<nxt2[j];++k)
                    v2.push_back(a[k].second);
                break;
            }
            if (z1) swap(v1,v2);
            cout<<v1.size()<<" "<<v2.size()<<'\n';
            for (int i=0;i<v1.size();++i)
                cout<<v1[i]<<" ";
            cout<<'\n';
            for (int i=0;i<v2.size();++i)
                cout<<v2[i]<<" ";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x1>>x2;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    solve(x1,x2,0);
    solve(x2,x1,1);
    cout<<"No";
}