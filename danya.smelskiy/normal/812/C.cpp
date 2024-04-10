#include <bits/stdc++.h>
using namespace std;


int n;
long long m;
pair<long long,int > a[100005];

int k;

inline bool cmp(pair<long long,long long> a,pair<long long,long long> b){
    return a.first+a.second*k<=b.first+b.second*k;
}
inline long long chek(long long mid){
    k=mid;
    sort(a+1,a+n+1,cmp);
    long long sum=0;
    for (int i=1;i<=mid;++i)
        sum+=a[i].first+a[i].second*mid;
    if (sum>m) return 0;
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    long long l=1;
    long long r=n;
    while (l<r-1) {
        long long mid=(l+r)/2;
        if (chek(mid)) l=mid;
        else r=mid;
    }
    long long x=chek(r);
    if (x) cout<<r<<" "<<x;
    else {
        x=chek(l);
        if (x) cout<<l<<" "<<x;
        else cout<<"0 0";
    }
}