#include <iostream>
#include <cstdio>

using namespace std;
typedef int var;

char a[200000], b[200000], c[200000];
var A[30], B[30], C[30], AB[30];

void Read(char C[], var V[]) {
    cin>>C;
    for(var i=0; C[i]; i++) {
        V[C[i]-'a']++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    Read(a, A);
    Read(b, B);
    Read(c, C);

    var maxc = 0, noC = 0, noB = 0;

    var countB = 0;
    var countC;

    for(var i=0; i<='z'-'a'; i++) {
        AB[i] = A[i];
    }

    bool tru = true;
    while(tru) {
        countC = 500000;

        for(var i=0; i<='z'-'a'; i++) {
            if(C[i])
                countC = min(countC, A[i] / C[i]);
        }

        if(maxc < countB + countC) {
            maxc = countB + countC;
            noB = countB;
            noC = countC;
        }

        for(var i=0; i<='z'-'a'; i++) {
            if(A[i] < B[i]) {
                tru = false; break;
            }
            A[i] -= B[i];
        }
        countB++;
    }

    for(var i=0; i<='z'-'a'; i++) {
        AB[i] -= noB * B[i] + noC * C[i];
        for(var j=0; j<AB[i]; j++) {
            cout<<char(i+'a');
        }
    }

    for(var i=0; i<noB; i++) {
        cout<<b;
    }
    for(var i=0; i<noC; i++) {
        cout<<c;
    }

    return 0;
}