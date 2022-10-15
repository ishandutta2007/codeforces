#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000000+5;
int n;
int a[N];
int b[N];
int f[N];

int mi[N],ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        f[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        b[i]=f[x];
    }
    reverse(b+1,b+n+1);
    ans=1;
    mi[ans]=b[1];
    for(int i=2;i<=n;i++) {
        if(b[i]>mi[ans]) {
            ans++;
            mi[ans]=b[i];
            continue;
        }
        int r=0,pas=(1<<19);
        while(pas) {
            if(r+pas<=ans && b[i]>=mi[r+pas]) {
                r+=pas;
            }
            pas/=2;
        }
        r++;
        mi[r]=b[i];
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/