#include <bits/stdc++.h>
using namespace std;




int n;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int res=0;
    while (n) {
        ++res;
        n/=2;
    }
    cout<<res;
}