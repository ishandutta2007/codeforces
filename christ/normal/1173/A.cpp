#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,y,z;
    scanf ("%d %d %d",&x,&y,&z);
    int v1 = x-y+z, v2=x-y-z;
    if (v1 == 0 && v2 == 0) return !printf ("0\n");
    else if (v1 == 0 || v2 == 0 || v1 < 0 != v2 < 0) return !printf ("?\n");
    else if (v1 < 0) return !printf ("-\n");
    return !printf ("+\n");
}