#include <bits/stdc++.h>
using namespace std;

int n;
int a[300005];
pair<int,int> b[300005];
int c[300005];
inline bool cmp(pair<int,int> a,pair<int,int> b){
    if (a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;++i) {
        c[b[i].second]=a[n-i+1];
    }
    for (int i=1;i<=n;++i)
        cout<<c[i]<<" ";
}