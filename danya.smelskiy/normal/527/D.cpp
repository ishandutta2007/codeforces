#include <bits/stdc++.h>
using namespace std;


int ans,n,last;
pair<int,int> a[200005];

inline bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first+a.second<=b.first+b.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    a[0]=make_pair(-1e9,-1e9);
    int last=0;
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (a[i].first-a[i].second>=a[last].first+a[last].second) {
            ++ans;
            last=i;
        }
    }
    cout<<ans;
}