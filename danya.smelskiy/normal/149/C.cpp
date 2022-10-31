#include <bits/stdc++.h>
using namespace std;




int n;
pair<int,int> a[100005];
vector<int> v[2];

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        v[i%2].push_back(a[i].second);
    for (int i=0;i<2;++i) {
        cout<<v[i].size()<<'\n';
        for (int j=0;j<v[i].size();++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }

}