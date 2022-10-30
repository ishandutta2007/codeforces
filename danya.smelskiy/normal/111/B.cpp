#include <bits/stdc++.h>
using namespace std;

int n;
int ans[100005];
vector<int> v[100005];
int x,y;
int last[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=1e5;++i)
        for (int j=i;j<=1e5;j+=i){
            v[j].push_back(i);
        }
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        int res=0;
        if (y==0) {
            cout<<v[x].size()<<'\n';
            for (int j=0;j<v[x].size();++j) {
                int z=v[x][j];
                last[z]=i;
            }
            continue;
        }
        for (int j=0;j<v[x].size();++j) {
            int z=v[x][j];
            if (last[z]<i-y) {  ++res;}
            last[z]=i;
        }
        cout<<res<<'\n';
    }
}