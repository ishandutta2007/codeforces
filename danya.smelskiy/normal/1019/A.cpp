#include <bits/stdc++.h>
using namespace std;








int n,m;
long long ans=1e18;
pair<long long,long long >a[3005];
long long cnt1[3005];
long long cnt2[3005];
int x;
bool used[3005];


int main() {
//    freopen("input_01.txt","r",stdin);
  //  freopen("output_01.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        ++cnt1[a[i].second];

    for (int i=1;i<=n;++i) {
        long long s=0;
        for (int j=1;j<=m;++j)
            cnt2[j]=cnt1[j];
        for (int j=1;j<=n;++j) {
            used[j]=false;
            x=a[j].second;
            if (x==1) continue;
            if (cnt2[x]>=i) {
                --cnt2[x];
                ++cnt2[1];
                used[j]=true;
                s+=a[j].first;
            }
        }
        for (int j=1;j<=n;++j) {
            x=a[j].second;
            if (x==1 || used[j]) continue;
            if (cnt2[1]<i) {
                ++cnt2[1];
                s+=a[j].first;
            }
        }
//        cout<<"<"<<i<<" "<<s<<'\n';
        if (cnt2[1]>=i) ans=min(ans,s);
    }
    cout<<ans;
}