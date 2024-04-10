#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
using namespace std;
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    int ans = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s;
        if (s=="Tetrahedron") ans += 4;
        if (s=="Cube") ans += 6;
        if (s=="Octahedron") ans += 8;
        if (s=="Dodecahedron") ans += 12;
        if (s=="Icosahedron") ans += 20;
    }
    cout << ans << endl;
    return 0;
}