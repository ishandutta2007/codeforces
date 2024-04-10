#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
int n,val,v[N+5];
int poz;
int mi[N+5],ma[N+5];
int ap[2*N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>val;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]==val)
            poz=i;
        mi[i]=mi[i-1];
        ma[i]=ma[i-1];
        if(v[i]<val)
            mi[i]++;
        if(v[i]>val)
            ma[i]++;
    }
    ll ans=0;
    for(int k=1;k<=2;k++) {
        for(int i=0;i<=2*N;i++)
            ap[i]=0;
        for(int i=poz;i<=n;i++) {
            int dif=mi[i]-ma[i]+N;
            ap[dif]++;
        }
        for(int i=1;i<=poz;i++) {
            int dif=mi[i-1]-ma[i-1]+N-(k-1);
            ans+=ap[dif];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/