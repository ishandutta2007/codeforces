#include <bits/stdc++.h>

using namespace std;
typedef int var;

#define MAXN 101

bool Added[MAXN];
char A[MAXN][MAXN];
var Bad[MAXN];
var D[MAXN];
var added;
var n;

bool Add(var i) {
    Added[i] = 1;
    added++;

    for(var j=1; j<=n; j++)
        if(A[i][j] == '1')
            D[j]++;
}

void Rem(var i) {
    Added[i] = 0;
    added--;

    for(var j=1; j<=n; j++)
        if(A[i][j] == '1')
            D[j]--;
}

void Xor(var i) {
    if(Added[i]) Rem(i);
    else Add(i);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    srand(time(NULL));

    cin>>n;
    for(var i=1; i<=n; i++)
        cin>>A[i] + 1;

    for(var i=1; i<=n; i++)
        cin>>Bad[i];

    for(var i=1; i<=n; i++)
        if(rand() % 2)
            Add(i);

    bool over = 0, it = 0;
    while(!over) {
        over = 1;
        it++;
        if(it > 1000) {cout<<-1; return 0;}

        for(var i=1; i<=n; i++) {
            if(D[i] == Bad[i]) {
                Xor(i); over = 0;
            }
        }
    }

    cout<<added<<'\n';
    for(var i=1; i<=n; i++) {
        if(Added[i])
            cout<<i<<" ";
    }
    return 0;
}