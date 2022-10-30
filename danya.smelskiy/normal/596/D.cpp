#include <bits/stdc++.h>
using namespace std;


bool used[2005][2005][2][2];
long double ans[2005][2005][2][2];
int n;
int lf[2005],rf[2005];
long double a[2005];
long long h;
long double p;
long double get(int l,int r,int t1,int t2){
    if (l>r) return 0;
    if (used[l][r][t1][t2]) return ans[l][r][t1][t2];
    used[l][r][t1][t2]=true;

    long double q=get(l+1,r,0,t2)*p/2;
    long double rr=a[lf[l]]-h;
    long double ll;
    if (t1) ll=a[l-1]+h;
    else ll=a[l-1];
    rr=max(rr,ll);
    ans[l][r][t1][t2]+=q+(fabs(a[l]-rr)*p/2);

    q=get(l,r-1,t1,1)*(1.-p)/2;
    rr=a[rf[r]]+h;
    if (t2) ll=a[r+1];
    else ll=a[r+1]-h;
    rr=min(rr,ll);
    ans[l][r][t1][t2]+=q+(fabs(a[r]-rr)*(1.-p)/2);

    q=get(rf[l]+1,r,1,t2)*(1.-p)/2;
    ll=a[rf[l]]+h;
    if (t2) rr=a[r+1];
    else rr=a[r+1]-h;
    ll=min(ll,rr);
    ans[l][r][t1][t2]+=q+(fabs(a[l]-ll)*(1.-p)/2);

    q=get(l,lf[r]-1,t1,0)*p/2;
    ll=a[lf[r]]-h;
    if (t1) rr=a[l-1]+h;
    else rr=a[l-1];
    ll=max(ll,rr);
    q+=(fabs(a[r]-ll)*p/2);
    ans[l][r][t1][t2]+=q;
    return ans[l][r][t1][t2];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>h>>p;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[0]=-1e9;
    a[n+1]=1e9;
    for (int i=1;i<=n;++i) {
        lf[i]=rf[i]=i;
        while (a[lf[i]-1]>a[lf[i]]-h) --lf[i];
        while (a[rf[i]+1]<a[rf[i]]+h) ++rf[i];
    }
    cout<<fixed<<setprecision(9)<<get(1,n,1,0);
}