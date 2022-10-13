#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

#define x first
#define y second

Pair P[2000000];
int I[2000000];

bool cmpx(int a, int b) {
    return P[a].x < P[b].x;
}
bool cmpy(int a, int b) {
    return P[a].y < P[b].y;
}

void Sort(int b, int e, bool x) {
    if(e <= b) return;

    int m = b+(e-b)/2;

    if(x) nth_element(I+b, I+m, I+e+1, cmpx);
    else  nth_element(I+b, I+m, I+e+1, cmpy);

    Sort(b, m-1, x^1);
    Sort(m+1, e, x^1);

}

void read(int &x) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(x = 0; isdigit(c); x = x*10+c-'0', c = getchar());
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    read(n);
    for(int i=1; i<=n; i++) {
        read(P[i].x); read(P[i].y);
        I[i] = i;
    }

    Sort(1, n, 0);

    for(int i=1; i<=n; i++) {
        cout<<I[i]<<" ";
    }

    return 0;
}