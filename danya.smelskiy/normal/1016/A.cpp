#include <bits/stdc++.h>
using namespace std;



int n;
long long m,s,ss;
long long x;

int main() {
//    freopen("army.in","r",stdin);
  //  freopen("army.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ss=s+x;
        cout<<ss/m-(s/m)<<" ";
        s=ss;
    }
}