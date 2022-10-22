#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        long long a,b,k,r;
        cin >> a >> b >> k;
        r=(a-b)*(k/2);
        if(k%2==1) r+=a;
        cout << r << '\n';
    }
    return 0;
}