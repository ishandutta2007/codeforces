#include <bits/stdc++.h>
using namespace std;

int n,k,p;
int a[100005];
vector<int> v,vv;
vector<int> ans[100005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>p;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        int x=a[i];
        if (x&1) v.push_back(x);
        else vv.push_back(x);
    }
    int x=v.size();
    int free=x-(k-p);
    if (x%2!=(k-p)%2 || x<(k-p) || vv.size()+free/2<p) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    int last=1;
    for (int i=0;i<vv.size();++i) {
        int x=vv[i];
        ans[last].push_back(x);
        ++last;
        if (last==p+1) last=1;
    }
    for (int i=0;i<k-p;++i)
        ans[p+i+1].push_back(v[i]);
    if (p) {
    for (int i=k-p;i<v.size();i+=2) {
        ans[last].push_back(v[i]);
        ans[last].push_back(v[i+1]);
        ++last;
        if (last==p+1) last=1;
    } }else {
        for (int i=k-p;i<v.size();++i)
            ans[1].push_back(v[i]);
    }
    for (int i=1;i<=k;++i) {
        cout<<ans[i].size()<<" ";
        for (int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}