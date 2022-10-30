#include <bits/stdc++.h>
using namespace std;

int n;
pair<long long,long long> a[200005];
long long b[200005];
long long x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        x+=a[i].first;
        b[i]=a[i].second;
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i){
        long long y=x-a[i].first;
        if (a[i].second==b[n]) cout<<y*(b[n-1])<<" ";
        else cout<<y*(b[n])<<" ";

    }
}