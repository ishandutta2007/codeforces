#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;

int n,k,a[N];
int v[N];
ll sum=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        int b;
        cin>>b;
        v[i]=a[i]-b;
        sum+=b;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=k;i++) {
        sum+=v[i];
    }
    int poz=k+1;
    while(poz<=n && v[poz]<0) {
        sum+=v[poz];
        poz++;
    }
    cout<<sum<<"\n";
    return 0;
}