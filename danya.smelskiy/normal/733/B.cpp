#include <bits/stdc++.h>
using namespace std;
int n;
long long ans,pos,l,r,ll,rr,k;
pair<int,int> a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        l+=a[i].first;
        r+=a[i].second;
    }
    ans=abs(l-r);
    pos=0;
    for (int i=1;i<=n;++i){
        ll=l;
        rr=r;
        ll-=a[i].first;
        rr-=a[i].second;
        ll+=a[i].second;
        rr+=a[i].first;
        k=abs(ll-rr);
        if (k>ans){
            pos=i;
            ans=k;
        }
    }
    cout<<pos;
}