#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<pair<int,int> ,int > > v;
pair<int,int> ans[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(make_pair(x,1-y),i));
    }
    sort(v.begin(),v.end());
    int ll=1,rr=1;
    int r=1;
    for (int i=0;i<v.size();++i) {
        if (v[i].first.second==0) ans[v[i].second]=make_pair(1,++r);
        else {
            ++ll;
            while (ll>=rr)  {
                ll=2,++rr;
                if(rr>r) {
                    cout<<"-1";
                    return 0;
                }
            }
            ans[v[i].second]=make_pair(ll,rr);
        }
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}