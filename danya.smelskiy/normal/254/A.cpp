#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[5005];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n+n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    for (int i=1;i<=5000;++i)
    if ((v[i].size())&1) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=5000;++i)
        for (int j=0;j<v[i].size();j+=2)
            cout<<v[i][j]<<" "<<v[i][j+1]<<'\n';
}