#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;
int n,r;
int x[N];
ld ans[N];

bool touch(int a,int b) {
    int dist=abs(a-b);
    return (dist<=2*r);
}

ld pp(ld a) {
    return (ld)a*a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>r;
    for(int i=1;i<=n;i++) {
        cin>>x[i];
    }
    ans[1]=r;
    for(int i=2;i<=n;i++) {
        ans[i]=r;
        for(int j=1;j<i;j++) {
            if(touch(x[j],x[i])==0) {
                continue;
            }
            ld sq=pp(2*r)-pp(x[j]-x[i]);
            if(sq<0) {
               /// cout<<"ERROR\n";
                continue;
            }
            sq=(ld)sqrt(sq);
            ans[i]=max(ans[i],sq+ans[j]);
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<fixed<<setprecision(6)<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**


**/