#include <bits/stdc++.h>
using namespace std;
int main() {
    int s,v1,v2,t1,t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int r1=0,r2=0;
    r1+=2*t1;
    r2+=2*t2;
    r1+=v1*s;
    r2+=v2*s;
    if(r1<r2) cout << "First";
    else if(r1==r2) cout << "Friendship";
    else cout << "Second";
    return 0;
}