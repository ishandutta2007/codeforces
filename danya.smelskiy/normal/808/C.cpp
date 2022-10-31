#include <bits/stdc++.h>
using namespace std;

int n,w;
pair<int,int> a[105];
int b[105];
int ans[105];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>w;
    for (int i=1;i<=n;++i)  {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        b[i]=(a[i].first+1)/2;
        w-=b[i];
    }
    if (w<0) {
        cout<<"-1";
        return 0;
    }
    for (int i=n;i>0;--i) {
        int mx=min(a[i].first-b[i],w);
        w-=mx;
        b[i]+=mx;
        ans[a[i].second]=b[i];
    }
    if (w) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}