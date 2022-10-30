#include <bits/stdc++.h>
using namespace std;

long long x,y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    if (y==1 && x) {
        cout<<"No";
        return 0;
    }
    --y;
    x-=y;
    if (x<0 || y<0) {
        cout<<"No";
        return 0;
    }
    if (x%2ll) {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
}