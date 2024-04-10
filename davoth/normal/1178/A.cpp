#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,mx=0,cx;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        mx+=a[i];
    }
    mx/=2;
    vector<int> c;
    c.push_back(0);
    cx=a[0];
    for(int i=1; i<n; i++){
        if(a[i]*2<=a[0]){
            c.push_back(i);
            cx+=a[i];
        }
    }
    if(cx<=mx) cout << 0;
    else{
        cout << c.size() << '\n';
        for(int i=0; i<c.size(); i++){
            cout << c[i]+1 << ' ';
        }
    }
    return 0;
}