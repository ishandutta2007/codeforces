#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;
int n,v[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    int mi=v[2]-v[1];
    for(int i=3;i<=n;i++) {
        mi=min(mi,v[i]-v[i-1]);
    }
    int cnt=0;
    for(int i=2;i<=n;i++) {
        if(v[i]-v[i-1]==mi) {
            cnt++;
        }
    }
    cout<<mi<<" "<<cnt<<"\n";
    return 0;
}