#include <bits/stdc++.h>
using namespace std;


int n,m;
long long ans;
vector<int> v[200005];
vector<int> q;
int last;
int cnt[200005];

int x;
int a[200005];
int b[200005];


inline int update(int x,int y) {
    int xx=a[x]%m;
    int len=(y+m-xx)%m;
    b[x]=a[x]+len;
    return len;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        v[a[i]%m].push_back(i);
    }
    for (int it=0;it<2;++it) {
        for (int i=0;i<m;++i) {
            for (int j=0;j<v[i].size();++j) {
                q.push_back(v[i][j]);
            }
            v[i].clear();
            while (last<q.size() && cnt[i]<n/m) {
                x=q[last++];
                ans+=update(x,i);
                ++cnt[i];
            }
        }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
}