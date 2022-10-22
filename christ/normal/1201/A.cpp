#include<bits/stdc++.h>
using namespace std;
char ans[1005][1005];
int a[1005];
int freq[10];
int main () {
    int n,m; int tot = 0;
    scanf ("%d %d",&n,&m);
    for (int i = 0; i < n; i++) scanf ("%s",ans[i]);
    for (int i = 0; i < m; i++) {
      memset(freq,0,sizeof freq); int mx = 0;
      scanf ("%d",&a[i]);
      for (int j = 0; j < n;j++) {
        mx = max(mx,++freq[ans[j][i] - 'A']);
      }
      tot += mx * a[i];
    }
    printf ("%d\n",tot);
    return 0;
}