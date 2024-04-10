#include <bits/stdc++.h>
using namespace std;

int n,k,a[100];
vector<vector<int> > v[100];
map<int,bool> used;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    vector<int> z;
    z.push_back(0);
    v[0].push_back(z);
    for (int i=0;i<n;++i) {
        v[i+1]=v[i];
        if (v[i].size()>k) continue;
        for (int j=0;j<v[i].size() && v[i+1].size()<=k;++j) {
            int x=v[i][j][0];
            if (used[x+a[i+1]]==false) {
                used[x+a[i+1]]=true;
                vector<int> zz=v[i][j];
                zz[0]+=a[i+1];
                zz.push_back(a[i+1]);
                v[i+1].push_back(zz);
            }
        }
    }
    for (int i=1;i<v[n].size();++i) {
        cout<<v[n][i].size()-1<<" ";
        for (int j=1;j<v[n][i].size();++j) {
            cout<<v[n][i][j]<<" ";
        }
        cout<<'\n';
    }
}