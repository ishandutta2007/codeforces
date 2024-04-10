#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    scanf ("%d %d %d",&a,&b,&c);
    printf (min(b,c) >= a ? "YES\n" : "NO\n");
    return 0;
}