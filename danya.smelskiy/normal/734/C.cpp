#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x,s,ans;
long long kol,sum;
pair<long long,long long> a[200001],b[200001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    cin>>x>>s;
    ans=n*x;
    for (int i=1;i<=m;++i)
        cin>>a[i].first;
    for (int i=1;i<=m;++i)
        cin>>a[i].second;
    for (int i=1;i<=k;++i)
        cin>>b[i].first;
        long long z=0;
    for (int i=1;i<=k;++i){
        cin>>b[i].second;
        if (b[i].second<=s){
            ans=min(ans,max(z,n-b[i].first)*x);
        }
        b[i].first=max(b[i].first,b[i-1].first);
    }
    b[k+1].first=10000000000;
    for (int i=1;i<=m;++i){
            kol=a[i].first;
            sum=a[i].second;
            if (sum>s) continue;
            ans=min(ans,n*kol);
            sum=s-sum;
            if (b[1].second>sum) continue;
            long long l=1;
            long long r=k+1;
            while(l<r-1){
                long long mid=(l+r)/2;
                if (b[mid].second>sum) r=mid;
                else l=mid;
            }
            //cout<<b[l].first<<endl;
            //if (b[r].second<=sum) l=r;
            //cout<<n-1-b[l].first<<"."<<endl;
            if (b[l].first==n-1){
                ans=min(ans,kol);
            } else if (b[l].first<n-1){
              //s  cout<<".";
                ans=min(ans,((n-b[l].first)*kol));
                //cout<<ans<<"!";
            }
    }
    cout<<ans;
}