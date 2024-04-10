#include <bits/stdc++.h>

using namespace std;



#define MAXN 5005

char str[10000];

int DP[MAXN][MAXN], SP[MAXN][MAXN], MaxL[MAXN][MAXN];

const int MOD = 1e9 + 7;

bool good(int a, int b, int l) {
    if(a <= 0 || b <= 0) return false;
    int x = MaxL[a][b];
    if(x >= l) return false;
    a += x;
    b += x;
    return str[a] > str[b];
}

void Dump(int A[MAXN][MAXN], int n) {
    for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
        cout << A[i][j] << " ";
    }
    cout << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE



    int n;
    cin>>n>>str + 1;

    for(int i=n; i; i--)
    for(int j=n; j>i; j--) {
        if(str[i] == str[j]) {
            MaxL[i][j] = MaxL[i+1][j+1] + 1;
            MaxL[j][i] = MaxL[i][j];
        }
    }

    for(int i=0; i<=n; i++)
        SP[0][i] = 1;




    for(int i=1; i<=n; i++) {

        for(int maxx=1; maxx<=n; maxx++) {
            int suffa = i - maxx + 1;
            int suffb = i - 2*maxx + 1;

            if(i - maxx >= 0 && str[suffa] != '0') {
                if(good(suffa, suffb, maxx))
                    DP[i][maxx] = SP[i-maxx][maxx];
                else
                    DP[i][maxx] = SP[i-maxx][maxx - 1];
            }

            SP[i][maxx] = SP[i][maxx-1] + DP[i][maxx];
            if(SP[i][maxx] >= MOD) SP[i][maxx] -= MOD;
        }
    }

    //Dump(DP, n);

    cout << SP[n][n];



    return 0;
}