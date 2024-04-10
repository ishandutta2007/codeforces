#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[4],r=0;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    string s;
    cin >> s;
    for(char i : s){
        if(i=='1') r+=a[0];
        if(i=='2') r+=a[1];
        if(i=='3') r+=a[2];
        if(i=='4') r+=a[3];
    }
    cout << r;
    return 0;
}