#include<bits/stdc++.h>
using namespace std;
const int MN = 5e3+3;
int bit[MN][MN];
int a[MN];
void inc (int x, int y) {
    for (x++;x<MN;x+=x&-x)
        for(int i=y+1;i<MN;i+=i&-i)
            ++bit[x][i];
}
int query (int x, int y) {
    int ret = 0;
    for (x++;x;x^=x&-x)
        for(int i=y+1;i;i^=i&-i)
            ret += bit[x][i];
    return ret<<1;
}
int main() {
    int n,inv=0;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++) {
            scanf ("%d",a+i);
            inc(i,a[i]);
            for (int j = i-1; j >= 0; j--) if (a[j] > a[i]) ++inv;
    }
    int mn = INT_MAX, cnt = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) if (a[i] > a[j]) {
            int att = inv-1-query(j-1,a[i])+query(i,a[i])+query(j-1,a[j]-1)-query(i,a[j]-1);
            if (att < mn) {mn = att; cnt = 1;}
            else if (att == mn) ++cnt;
        }
    }
    printf ("%d %d\n",mn,cnt);
    return 0;
}