#include <bits/stdc++.h>

using namespace std;

#define MAXN 500000

long long V[MAXN], I[MAXN];
long long SP[MAXN];
long long A;
long long n;

long long solve(long long have, long long maxi) {

    long long i, sol = 0;

    for(i=1; i<=A; i<<=1LL);
    for(i>>=1LL; i; i>>=1LL) {
        long long check = sol + i;
        V[n + 5] = check;

        if(check > A) continue;

        long long k = lower_bound(I+1, I+maxi+1, n + 5, [](long long a, long long b) {return V[a] < V[b];}) - I - 1;
        if(have >= 1LL * k * check - SP[k])
            sol = check;
    }

    return sol;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif

    long long cf, cm;
    long long m;

    cin >> n >> A >> cf >> cm >> m;

    for(long long i = 1; i <= n; i += 1) {
        cin >> V[i];
        I[i] = i;
    }

    sort(I + 1, I + n + 1, [](long long a, long long b) {return V[a] < V[b];});

    for(long long i=1; i<=n; i++)
        SP[i] = SP[i-1] + V[I[i]];

    long long best = 0;
    long long need = 0;
    long long gotmax = 0;

    long long maximize = n + 1;
    long long minv = 0;

    long long mm = m;


    for(long long i = n + 1; i > 0; i -= 1) {

        long long now = solve(m, i - 1);

        if(best < gotmax + 1LL * cm * now) {
            best = gotmax + 1LL * cm * now;
            maximize = i;
            minv = now;
        }

        m -= A - V[I[i-1]];
        gotmax += cf;

        if(m < 0) break;

    }

    long long cost = 0;

    for(long long i = maximize; i <= n; i += 1) {
        cost += A - V[I[i]];
        V[I[i]] = A;
    }

    minv = min(minv, A);

//    assert(minv <= A);

//    minv -= 1;

    for(long long i = 1; i <= n; i += 1) {
        if(V[I[i]] <= minv) {
            cost += minv - V[I[i]];
            V[I[i]] = minv;
        }
    }

//    assert(cost <= mm);


    for(int i = 1; i <= min(n, mm - cost); i += 1)
        if(V[I[i]] < A)
            V[I[i]] += 1;

    long long minn = 1e18;
    int cnt = 0;

    for(int i = 1; i <= n; i += 1) {
        minn = min(minn, V[i]);
        if(V[i] == A) cnt += 1;
    }

    cout << minn * cm + cnt * cf << '\n';
    for(long long i = 1; i <= n; i += 1) {
        cout << V[i] << " ";
    }

    return 0;
}