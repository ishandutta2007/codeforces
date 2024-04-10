#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long p[1001];
long long pp[1001];
pair<long long ,long long > a[1001];

inline bool cmp(pair<long long,long long> a,pair<long long,long long> b){
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    cin>>m;
    for (long long i=1;i<=m;++i)
        cin>>p[m-i+1];
    sort(a+1,a+n+1,cmp);
    for (long long i=m-1;i>0;--i)
        pp[i]=p[i]-p[i+1];
    pp[m]=p[m];
    long long t=1;
    for (long long i=1;i<=n;++i) {
        while (true) {
            long long z=a[i].first;
            if (m) z=min(z,pp[m]);
            ans+=a[i].second*t*z;
            a[i].first-=z;
            if (m) pp[m]-=z;
            if (m && pp[m]==0) { ++t; --m;}
            if (a[i].first==0) break;
        }
    }
    cout<<ans;
}