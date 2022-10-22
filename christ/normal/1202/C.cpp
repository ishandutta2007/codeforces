#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[300000];
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
        scanf("%s",a); int len = strlen(a);
        int up,right,minup,minright,maxup,maxright,minupind,minrightind,maxupind,maxrightind,minuplast,minrightlast,maxuplast,maxrightlast;
        up = right = minup = minright = maxup = maxright = 0;
        minupind = minrightind = maxupind = maxrightind = minuplast = minrightlast = maxuplast = maxrightlast = -1;
        for (int i = 0; i < len; i++) {
            if (a[i] == 'W') up++;
            else if (a[i] == 'S') up--;
            else if (a[i] == 'A') right--;
            else right++;
            if (right > maxright) {
                maxright = right;
                maxrightind = maxrightlast = i;
            }
            else if (right == maxright) maxrightlast = i;
            if (right < minright) {
                minright = right;
                minrightind = minrightlast = i;
            }
            else if (right == minright) minrightlast = i;
            if (up > maxup) {
                maxup = up;
                maxupind = maxuplast = i;
            }
            else if (up == maxup) maxuplast = i;
            if (up < minup) {
                minup = up;
                minupind = minuplast = i;
            }
            else if (up == minup) minuplast = i;
        }
        bool upposs=0, downposs=0, rightposs=0, leftposs=0;
        downposs = maxuplast < minupind-1;
        upposs = minuplast < maxupind-1;
        rightposs = minrightlast < maxrightind-1;
        leftposs = maxrightlast < minrightind-1;
        //printf ("minup %d, minright %d, maxup %d, maxright %d, minupind %d, minrightind %d, maxupind %d, maxrightind %d, minuplast %d, minrightlast %d, maxuplast %d, maxrightlast %d\n",minup,minright,maxup,maxright,minupind,minrightind,maxupind,maxrightind,minuplast,minrightlast,maxuplast,maxrightlast);
        ll ans = (maxup-minup+1)*1LL*(maxright-minright+1);
        if (downposs || upposs) ans = (maxup-minup)*1LL*(maxright-minright+1);
        if (rightposs || leftposs) ans = min(ans,(maxup-minup+1)*1LL*(maxright-minright));
        printf ("%lld\n",ans);
    }
    return 0;
}