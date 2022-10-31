#include <bits/stdc++.h>
using namespace std;
int n,k,r;
long long ans;
pair<int,int> a[100001];
bool cmp(pair<int,int> a,pair<int,int> b){
    return(a.first<b.first);
}

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
  //  cout<<a[n].first<<endl;
    for (int i=1;i<=n;++i){
        if (a[i].first+ans>k) break;
        else r=i;
        ans+=a[i].first;
    }
    cout<<r<<endl;
    ans=0;
    for (int i=1;i<=n;++i){
        ans+=a[i].first;
        if (ans<=k) cout<<a[i].second<<" ";
        else break;
    }
}