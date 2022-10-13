#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

char a[2000000], b[2000000];
int sa[2000000], sb[2000000];

int main() {
    cin>>a>>b;

    int t = 0;
    for(int i=strlen(a)-1; i>=0;i--) {
        sa[++t] = a[i] - '0';
    }
    t = 0;
    for(int i=strlen(b)-1; i>=0; i--) {
        sb[++t] = b[i] - '0';
    }

    int lb, la;
    for(la=1e6 + 1; la && sa[la] == 0; la--);
    for(lb=1e6 + 1; lb && sb[lb] == 0; lb--);

    if(la < lb) {cout << "<"; return 0;}
    if(la > lb) {cout << ">"; return 0;}

    for(int i=la; i; i--) {
        if(sa[i] < sb[i]) {cout << "<"; return 0;}
        if(sa[i] > sb[i]) {cout << ">"; return 0;}
    }
    cout << "=";
    return 0;
}