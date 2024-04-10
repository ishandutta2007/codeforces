#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[200];
int ans[205];
vector<int> a[3];
int c[3];


int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n+n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    for (int i=1;i<=100;++i) if (v[i].size()>=2) {
        ++c[1];
        ++c[2];
        for (int j=0;j<v[i].size();++j) {
            if (a[1].size()<a[2].size()) a[1].push_back(v[i][j]);
            else a[2].push_back(v[i][j]);
        }
    }
    for (int i=1;i<=100;++i) if (v[i].size()==1) {
        if (a[1].size()<a[2].size()) {
            ++c[1];
            a[1].push_back(v[i][0]);
        } else {
            ++c[2];
            a[2].push_back(v[i][0]);
        }
    }
    cout<<c[1]*c[2]<<endl;
    for (int i=1;i<=2;++i) {
        for (int j=0;j<a[i].size();++j)
            ans[a[i][j]]=i;
    }
    for (int i=1;i<=n+n;++i)
        cout<<ans[i]<<" ";
}