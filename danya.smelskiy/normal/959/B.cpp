#include <bits/stdc++.h>
using namespace std;



int n,m,k;
long long ans;
map<string,int> number;
long long a[100005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        number[s]=i;
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    while (m--) {
        int x;
        cin>>x;
        vector<int> v;
        long long mn=1e9;
        for (int i=1;i<=x;++i) {
            int y;
            cin>>y;
            v.push_back(y);
            mn=min(mn,a[y]);
        }
        for (int i=0;i<v.size();++i)
            a[v[i]]=min(a[v[i]],mn);
    }
    while (k--) {
        string s;
        cin>>s;
        int x=number[s];
        ans+=a[x];
    }
    cout<<ans;
}