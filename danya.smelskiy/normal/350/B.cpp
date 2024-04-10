#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int cnt[100005];
int p[100005];
int ans;
int q;

int main() {
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        cin>>p[i];
        ++cnt[p[i]];
    }
    for (int i=1;i<=n;++i) if (a[i]==1) {
        int x=i;
        int kol=0;
        while (x && cnt[x]<=1 && (a[x]==0 || x==i)) {
            ++kol;
            x=p[x];
        }
        if (kol>ans) {
            ans=kol;
            q=i;
        }
    }
    vector<int> v;
    cout<<ans<<endl;
    int f=q;
    while (q && cnt[q]<=1 && (a[q]==0 || q==f)) {
        v.push_back(q);
        q=p[q];
    }
    for (int i=v.size()-1;i>=0;--i)
        cout<<v[i]<<" ";
}