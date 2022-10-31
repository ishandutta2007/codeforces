#include <bits/stdc++.h>
using namespace std;

int n,m;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    vector<pair<int,int> > ans;
    int x=min(n,m);
    int y=0;
    while (x>=0) {
        ans.push_back(make_pair(x,y));
        --x; ++y;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}