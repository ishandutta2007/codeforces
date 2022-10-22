#include <bits/stdc++.h>
using namespace std;
char a[100005], b[100005];
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
        scanf ("%s %s",a,b);
        int ind1=0,ind2 =0,len1 = strlen(a), len2 = strlen(b), diff = len1-len2;
        for (int i = len1-1; i >= 0; i--) {
            if (b[i-diff] == '1') {
                ind1 = i;
                break;
            }
        }
        for (int i = ind1; i >= 0; i--) {
            if (a[i] == '1') {
                ind2 = i;
                break;
            }
        }
        printf ("%d\n",ind1-ind2);
    }
    return 0;
}