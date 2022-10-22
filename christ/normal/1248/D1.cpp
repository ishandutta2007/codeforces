#include<bits/stdc++.h>
using namespace std;
const int MN = 500+3;
char s[MN];
int freq[MN<<1];
int psa[MN];
int main() {
    int n,lz=0,mn=0,cur,ans,mx=0,f=1,se=1;
    scanf ("%d\n%s",&n,s);
    for (int ii = 0; ii < n; ii++) {
        for (int j = ii; j <n; j++) {
            swap(s[ii],s[j]);
            lz = 0; mn = 0; cur = 0; ans = 0;
            for (int i = 0; i < n; i++) {
                cur += s[i] == '(' ? 1 : -1;
                psa[i] = cur;
                if (cur < mn) mn = cur;
                ++freq[cur+500];
            }
            if (cur == 0 && mn == 0) ans++;
            for (int i = 0; i < n - 1; i++) {
                if (mn == psa[i] && freq[mn+500] == 0) mn++;
                lz += s[i]=='('?1:-1;
                --freq[psa[i]+500];
                cur += s[i]=='('?1:-1;
                ++freq[cur+500];
                if (cur < mn) mn = cur;
                if (cur == lz && mn >= lz) ans++;
            }
            if (ans > mx) {
                mx = ans;
                f = ii+1;
                se = j+1;
            }
            swap(s[ii],s[j]);
        }
    }
    return !printf ("%d\n%d %d\n",mx,f,se);
}