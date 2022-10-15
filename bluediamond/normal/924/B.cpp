#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;

int n,dif;
int v[N+5];
ld ans=-1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>dif;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int k=1;
    for(int i=1;i<=n;i++) {
        k=max(k,i+2);
        while(k+1<=n && v[k+1]-v[i]<=dif)
            k++;
        if(k<=n && v[k]-v[i]<=dif) {
            int j=i+1;
            ld f=(ld)(v[k]-v[j])/(ld)(v[k]-v[i]);
            ans=max(ans,f);
        }
    }
    if(ans==-1)
        cout<<ans<<"\n";
    else
        cout<<fixed<<setprecision(100)<<ans<<"\n";
    return 0;
}
/**

**/