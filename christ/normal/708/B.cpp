#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5+2;
typedef pair<int,int> pii;
int get (int n) {
    for (int i = 1; i <= 45000; i++) if (i*(i-1)/2 == n) return i;
    printf ("Impossible\n");
    exit(0);
}
bool pass;
string ret;
void stupid (int a, int b, int c, int d, int aa, int dd) {
    ret="";
    int n = a+d;
    if ((long long)n*(n-1)/2-aa-dd != c+b) return;
    int cur = d;
    for(;cur;cur--) {
        while (b>=cur) ret += '0', b-=cur;
        ret+='1';
    }
    while (ret.size() < n) ret += '0';
    int z = 0,hh=0;
    if (ret.size() != n) return;
    for (int i = 0; i < n; i++) {
        if (ret[i]=='1')z++;
        else hh+=z;
    }
    if (hh != c) return;
    for (char &c : ret) putchar(c);
    putchar(10);
    exit(0);
}
int main() {
    int aa,b,c,dd,a,d;
    scanf ("%d %d %d %d",&aa,&b,&c,&dd);
    a = get(aa); d = get(dd);
    stupid(a,b,c,d,aa,dd);
    if (a == 1) stupid(0,b,c,d,aa,dd);
    if (d == 1) stupid(a,b,c,0,aa,dd);
    if (a == 1 && d == 1) stupid(0,b,c,0,aa,dd);
    return !printf ("Impossible\n");
}