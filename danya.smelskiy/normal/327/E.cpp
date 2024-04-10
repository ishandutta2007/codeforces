#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
map<pair<int,long long>,long long > kol;

int n,m;
long long a[100],b[100];
long long f[100];
long long res;
map<long long,bool> used[25];
map<pair<long long,long long>,long long> dp[25][25];
inline long long solve1(long long x){
    kol.clear();
    int mid=(n+1)/2;
    for (int i=0;i<(1<<(n-mid));++i) {
        int bts=0;
        long long sum=0;
        for (int j=0;j<n-mid;++j)
        if (i&(1<<j)) {
            ++bts;
            sum+=a[mid+1+j];
        }
        kol[make_pair(bts,sum)]++;
    }
    long long res=0;
    for (int i=0;i<(1<<mid);++i) {
        int bts=0;
        long long sum=0;
        for (int j=0;j<mid && sum<=x;++j) if (i&(1<<j)){
            ++bts;
            sum+=a[j+1];
        }
        if (sum>x) continue;
        for (int j=0;j<=n-mid;++j) {
            res=(res+((f[bts+j]*f[n-bts-j])%md)*kol[make_pair(j,x-sum)]%md);
            if (res>=md) res-=md;
        }
    }
    return res;
}
void recurs1(int pos,int kol1,int kol2,long long sum1,long long sum2) {
    if (sum1>b[1]) return;
    if (sum2>b[2]-b[1]) return;
    if (pos==n+1){
        used[kol1][sum1]=true;
        ++dp[kol1][kol2][make_pair(sum1,sum2)];
        return;
    }
    recurs1(pos+1,kol1,kol2,sum1,sum2);
    recurs1(pos+1,kol1+1,kol2,sum1+a[pos],sum2);
    recurs1(pos+1,kol1,kol2+1,sum1,sum2+a[pos]);
}
void recurs2(int pos,int kol1,int kol2,long long sum1,long long sum2) {
    if (sum1>b[1]) return;
    if (sum2>b[2]-b[1]) return;
    int mid=(n+1)/2;
    if (pos==(mid+1)) {
    for (int i=0;i<=(n-mid);++i) if (used[i][b[1]-sum1])
        for (int j=0;j<=(n-mid-i);++j) if (dp[i][j][make_pair(b[1]-sum1,b[2]-b[1]-sum2)]){
            res=(res+(dp[i][j][make_pair(b[1]-sum1,b[2]-b[1]-sum2)]*f[kol1+i]*f[kol2+j])%md*f[mid-kol1-kol2+n-mid-i-j]%md);
            if (res>=md) res-=md;
        }
        return;
    }
    recurs2(pos+1,kol1,kol2,sum1,sum2);
    recurs2(pos+1,kol1+1,kol2,sum1+a[pos],sum2);
    recurs2(pos+1,kol1,kol2+1,sum1,sum2+a[pos]);
}
int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>b[i];
    if (m==2 && b[2]<b[1]) swap(b[1],b[2]);
    f[0]=1;
    for (long long i=1;i<=n;++i)
        f[i]=(f[i-1]*i)%md;
    res=f[n];
    if (!m) {
        cout<<res;
        return 0;
    }
    res=(res-solve1(b[1])+md)%md;
    if (m==1) {
        cout<<res;
        return 0;
    }
    res=(res-solve1(b[2])+md)%md;
    recurs1((n+1)/2+1,0,0,0,0);
    recurs2(1,0,0,0,0);
    cout<<res;
}