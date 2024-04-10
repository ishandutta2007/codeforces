#include <bits/stdc++.h>
using namespace std;
int n;
int last;
bool used[200001];
pair<int,int> a[200001];
vector<pair<int,int> > ans;

inline bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+2,a+n+1,cmp);
    last=2;
    used[1]=true;
    for (int i=1;i<=n;++i){
        if (used[i]==false) break;
        for (int j=1;j<=a[i].first && last<=n;++j){
            used[last]=true;
            ans.push_back(make_pair(a[i].second,a[last].second));
            ++last;
        }
    }
    if (last!=n+1) {
        cout<<"-1";
        return 0;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}