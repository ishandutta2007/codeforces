#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long ans;

inline long long f(long long x,long long y){
    long long res=(y)*(y+1)/2;
    if (y>=x) res-=(y-x)*(y-x+1)/2;
    x=n-x;
    y--;
    res+=y*(y+1)/2;
    if (y>=x) res-=(y-x)*(y-x+1)/2;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    m-=n;
    ++ans;
    long long l=0;
    long long r=1e9;
    while (l<r-1) {
        long long mid=(l+r)>>1;
        if (f(k,mid)<=m) l=mid;
        else r=mid;
    }
    if (f(k,r)<=m) cout<<1+r;
    else cout<<1+l;
}