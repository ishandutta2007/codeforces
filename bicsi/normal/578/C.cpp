#include<bits/stdc++.h>
using namespace std;


int V[500000];
int n;

double check(double x, bool output = 0) {
    double s1 = 0, s2 = 0;
    double best1 = 0, best2 = 0;

    for(int i=1; i<=n; i++) {
        s1 += double(V[i]) - x;
        s2 += double(V[i]) - x;

        if(s1 < 0) s1 = 0;
        if(s2 > 0) s2 = 0;

        best1 = max(best1, s1);
        best2 = min(best2, s2);
    }

    if(output) cout<<fixed<<setprecision(10)<<(best1 - best2) / 2;
    return best1 + best2;
}

char c, sgn;
void read(int &a) {
    for(sgn = 0, c = getchar(); !isdigit(c) && c != '-'; c = getchar());
    if(c == '-') {sgn = 1; c = getchar();}
    for(a = 0; isdigit(c); a = a*10+c-'0', c = getchar());
    if(sgn) a = -a;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

 //   int n;
    read(n);

    for(int i=1; i<=n; i++) {
        read(V[i]);
    }

    double l = -10000, r = 10000, m;
    while(true) {
        m = (l+r)/2;
        double rr = check(m);

        if(rr < -1e-6) r = m;
        else if(rr > 1e-6) l = m;
        else break;
    }

    check(m, 1);


    return 0;
}