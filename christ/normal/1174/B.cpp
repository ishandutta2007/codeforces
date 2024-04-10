#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
    int n,c1=0,c2=0;
    bool bad[2] = {1,1};
    scanf ("%d",&n);
    a.resize(n);
    for (auto &i : a) {
      scanf ("%d",&i);
      bad[i&1]=0;
    }
    if (!bad[0] && !bad[1]) sort(a.begin(),a.end());
    for (int x = 0; x < n; x++) {
      printf ("%d%c",a[x],x==n-1?'\n':' ');
    }

    return 0;
}