#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll st1,dr1;
ll st2,dr2;
ll k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>st1>>dr1>>st2>>dr2>>k;
    ll st=max(st1,st2);
    ll dr=min(dr1,dr2);
    if(st<=dr) {
        cout<<dr-st+1-(st<=k && k<=dr)<<"\n";
    }
    else {
        cout<<"0\n";
    }
    return 0;
}
/**


**/