#include<bits/stdc++.h>
using namespace std;
int main () {
    int n,a,mx=0;
    long long tot=0;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++) {
      scanf ("%d",&a);
      tot += a;
      mx = max(mx,a);
    }
    printf ((tot&1) || (mx > tot-mx)?"NO\n":"YES\n");
    return 0;
}