#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;
int n,caut;
bool viz[N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    caut=n;
    for(int i=1;i<=n;i++) {
        int foo;
        cin>>foo;
        viz[foo]=1;
        while(viz[caut]==1)
            cout<<caut--<<" ";
        cout<<"\n";
    }
    return 0;
}
/**

**/