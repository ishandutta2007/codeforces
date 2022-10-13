#include <bits/stdc++.h>

using namespace std;

double P[2][200000], S[2][200000];

int main() {

    int n, m, rnk;
    cin>>n>>m;

    if(m == 1) {
        cout<<1;
        return 0;
    }

    int maxx = 0;

    P[0][0] = 1;
    for(int x=0; x<=120000; x++)
        S[0][x] = 1;



    int total = 0;
    for(int i=1; i<=n; i++) {
        cin>>rnk;

        int cur = i & 1;
        int lst = cur ^ 1;

        P[cur][0] = S[cur][0] = 0;
        for(int x=1; x<=120000; x++) {
            P[cur][x] = S[lst][x-1];

            if(x - m - 1 >= 0) P[cur][x] -= S[lst][x-m-1];
            if(x - rnk >= 0) P[cur][x] -= P[lst][x - rnk];
            P[cur][x] /= (m-1);

            S[cur][x] = P[cur][x] + S[cur][x-1];
        }

        //assert(fabs(S[cur][120000] - 1.0) < 1e-9);


        total += rnk;
    }

    double rez = S[n & 1][total-1];
    cout <<fixed<<setprecision(15)<< 1.0 * rez * (m-1) + 1 << endl;


    return 0;
}