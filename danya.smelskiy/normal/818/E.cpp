#include <bits/stdc++.h>
using namespace std;

long long n,m;
map<long long ,long long > pos;
vector<pair<long long,long long> > v[1001];
long long qq[1001];
long long k[1001];
long long w[1001];

long long ans;
long long p,x;
long long last[1001];
long long get(long long x){
    long long z=qq[x]-k[x];
    while (last[x]<v[x].size()-1) {
        if (v[x][last[x]].first<=z) ++last[x];
        else break;
    }
    if (v[x][last[x]].first<=z) return v[x][last[x]].second;
    else {
        --last[x];
        return v[x][last[x]].second;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m==1){
        cout<<(n)*(n+1)/2;
        return 0;
    }
    for (long long j=2;j*j<=(m);++j) {
        if (m%j) continue;
        long long kol=0;
        while (m%j==0) {
            ++kol;
            m/=j;
        }
        ++p;
        pos[j]=p;
        k[p]=kol;
        w[p]=j;
    }
    if (m>1) {
        ++p;
        pos[m]=p;
        k[p]=1;
        w[p]=m;
    }
    for (int i=1;i<=p;++i)
        v[i].push_back(make_pair(0,0));
    for (int i=1;i<=n;++i) {
        cin>>x;
        for (long long j=1;j<=p;++j) {
            long long y=w[j];
            while (x%y==0) {
                ++qq[j];
                x/=y;
            }
        }
        long long mx=i;
        bool t=false;
        for (long long j=1;j<=p;++j)
            v[j].push_back(make_pair(qq[j],i));
        for (long long j=1;j<=p;++j) {
            if (qq[j]<k[j]) {
                t=true;
                break;
            }
        }
        if (t) continue;
        for (int i=1;i<=p;++i) {
            mx=min(mx,get(i));
        }
        ans+=mx+1;
    }
    cout<<ans<<'\n';
}