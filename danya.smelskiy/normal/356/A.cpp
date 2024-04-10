#include <bits/stdc++.h>
using namespace std;
int n,m;
set<int> s;
int l,r,x;
int ans[300001];
vector<int> to;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        s.insert(i);
    for (int i=1;i<=m;++i){
        cin>>l>>r>>x;
        to.clear();
        set<int>::iterator q=s.lower_bound(l);
        while (q!=s.end()){
            long long y=*q;
            if (y>r) break;
            if (y!=x) {ans[y]=x;
            to.push_back(y);
            }
            ++q;
        }
        for (int j=0;j<to.size();++j){
            s.erase(to[j]);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}