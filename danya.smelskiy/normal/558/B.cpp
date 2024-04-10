#include <bits/stdc++.h>
using namespace std;


int n;
int ansl,ansr;
int ans;
int last;
pair<int,int> a[100005];
int res=1e9;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        if (a[i].first==a[i-1].first) ++last;
        else last=1;
        ans=max(ans,last);
    }
    last=0;
    for (int i=1;i<=n;++i) {
        if (a[i].first==a[i-1].first) ++last;
        else last=1;
        if (last==ans && res>a[i].second-a[i-last+1].second+1) {
            res=a[i].second-a[i-last+1].second+1;
            ansl=a[i-last+1].second;
            ansr=a[i].second;
        }
    }
    cout<<ansl<<" "<<ansr;
}