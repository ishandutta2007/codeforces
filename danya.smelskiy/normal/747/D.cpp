#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200005];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]<0) a[i]=-1;
        else a[i]=0;
        if (a[i]==-1) --m;
    }
    if (m<0) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i)
        if (a[i]!=a[i-1]) ++ans;
    int st=-1;
    for (int i=1;i<=n;++i)
    if (a[i]<0) {
        st=i;
        break;
    }
    if (st==-1) {
        cout<<0;
        return 0;
    }
    int last=st;
    ++n;
    a[n]=-1;
    int ll=-1;
    for (int j=st+1;j<=n;++j)
        if (a[j]<0) {
            if (a[j-1]==0) {
                if (j==n) ll=j-last-1; else
                v.push_back(j-last-1);
            }
            last=j;
        }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i){
        int x=v[i];
        if (x<=m) {
            ans-=2;
            m-=x;
        } else break;
    }
    if (ll!=-1 && m>=ll) --ans;
    cout<<ans;
}