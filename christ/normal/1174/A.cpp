#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
    int n,c1=0,c2=0;
    scanf ("%d",&n);
    a.resize(n<<1);
    for (auto &i : a) scanf ("%d",&i);
    sort(a.begin(),a.end());
    for (int x = 0; x < n; x++) c1 += a[x];
    for (int x = n; x < (n<<1); x++) c2 += a[x];
    if (c1 == c2) return !printf ("-1\n");
    for (int x = 0; x < (n<<1); x++) {
      printf ("%d%c",a[x],x==(n<<1)-1?'\n':' ');
    }
    return 0;
}