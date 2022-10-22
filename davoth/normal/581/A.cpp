#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int c;
    if(a>b) c=0;
    else if(b>a) c=1;
    else c=2;
    int l=min(a,b);
    cout << l << ' ';
    a-=l;
    b-=l;
    if(!c) cout << a/2;
    else if(c==1) cout << b/2;
    else cout << 0;
    return 0;
}