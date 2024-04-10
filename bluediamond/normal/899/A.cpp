#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int x[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        x[a]++;
    }
    int t=min(x[1],x[2]);
    x[1]-=t;
    x[2]-=t;
    cout<<t+x[1]/3<<"\n";
    return 0;
}
/**

**/