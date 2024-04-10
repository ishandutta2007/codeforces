#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

pair<int, int> A[1000005];
int DP[1000005], Sum[1000005], UB[1000005];

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(a = 0; isdigit(c); c = getchar())
        a = a * 10 + c - '0';
}

int main() {
    int64_t n, l, k;

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    cin>>n>>l>>k;

    int64_t complete = l / n;
    int64_t incomplete = l % n;

    for(int i=0; i<n; i++) {
        Read(A[i].first);
        A[i].second = i < incomplete;
    }

    sort(A, A+n);

    int ub = 0;
    for(int i=0; i<n; i++) {
        while(A[ub+1].first == A[i].first) ub++;
        UB[i] = ub;
    }


    for(int i=0; i<n; i++)
        Sum[i] = 1;

    int total = 0;

    for(int i=1; i<=k; i++) {

        if(i-1 <= complete) {
            for(int j=0; j<n; j++) {
                if(!A[j].second) continue;
                total += Sum[UB[j]];
                if(total >= MOD) total -= MOD;
            }
        }

        if(i <= complete) {
            for(int j=0; j<n; j++) {

                DP[j] = Sum[UB[j]];
                Sum[j] = DP[j];

                if(j > 0) Sum[j] += Sum[j-1];
                if(Sum[j] >= MOD) Sum[j] -= MOD;


                total += 1LL * DP[j] * ( (complete - i + 1) % MOD) % MOD;
                if(total >= MOD) total -= MOD;

  //              cout<<DP[j]<<" ";
            }
//            cout<<endl;
        }

    }

    cout<<total;

    return 0;

}