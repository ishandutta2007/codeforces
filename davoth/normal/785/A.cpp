#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r=0;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s=="Cube") r+=6;
        else if(s=="Tetrahedron") r+=4;
        else if(s=="Octahedron") r+=8;
        else if(s=="Dodecahedron") r+=12;
        else r+=20;
    }
    cout << r;
    return 0;
}