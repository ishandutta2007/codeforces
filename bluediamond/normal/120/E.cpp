#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        cout<<1-x%2<<"\n";
    }
    return 0;
}
/**
s
**/