#include <bits/stdc++.h>
using namespace std;

long long x,y;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    while (x>0 && y>0) {
        if (x>=y+y) {
            long long z=(x/(y+y));
            x-=z*(y+y);
        } else if (y>=x+x) {
            long long z=(y/(x+x));
            y-=z*(x+x);
        } else break;
    }
    cout<<x<<" "<<y;
}