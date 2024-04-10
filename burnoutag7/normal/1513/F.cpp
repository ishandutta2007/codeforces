#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005],b[200005];
vector<pair<int,int>> h,l;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sum+=abs(a[i]-b[i]);
        if(a[i]>b[i])h.emplace_back(b[i],a[i]);
        if(a[i]<b[i])l.emplace_back(a[i],b[i]);
    }
    sort(h.begin(),h.end());
    sort(l.begin(),l.end());
    int ans=0,i=0,r=0;
    for(pair<int,int> &p:h){
        while(i<l.size()&&l[i].first<=p.first)r=max(r,l[i++].second);
        ans=max(ans,min(r,p.second)-p.first);
    }
    i=0,r=0;
    for(pair<int,int> &p:l){
        while(i<h.size()&&h[i].first<=p.first)r=max(r,h[i++].second);
        ans=max(ans,min(r,p.second)-p.first);
    }
    cout<<sum-ans*2;

    return 0;
}