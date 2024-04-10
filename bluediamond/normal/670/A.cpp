#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2000000+5;
int n,v[N],y=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i+1<N;i++) {
        if(i%7<=4) {
            v[++y]=0;
        }
        else {
            v[++y]=1;
        }
    }
    for(int i=1;i<=y;i++) {
        v[i]+=v[i-1];
    }
    int mi=v[n],ma=v[n];
    for(int i=2;n+i-1<=y;i++) {
        int x=v[n+i-1]-v[i-1];
        mi=min(mi,x);
        ma=max(ma,x);
    }
    cout<<mi<<" "<<ma<<"\n";
    return 0;
}
/**

**/