#include <bits/stdc++.h>

using namespace std;

const int SQRT_MAXN = 20000; //     N
const int S = 10000;
bool nprime[SQRT_MAXN], bl[S];
int n, primes[SQRT_MAXN], cnt;

int ans[4];

void get_all_primes() {
    int nsqrt;
    for (int i = 2; ; ++i) {
        if (i * i > n) {
            nsqrt = i - 1;
            break;
        }
    }
	for (int i=2; i<=nsqrt; ++i)
		if (!nprime[i]) {
			primes[cnt++] = i;
			if (i * 1ll * i <= nsqrt)
				for (int j=i*i; j<=nsqrt; j+=i)
					nprime[j] = true;
		}

	for (int k=0, maxk=n/S; k<=maxk; ++k) {
		memset (bl, 0, sizeof bl);
		int start = k * S;
		for (int i=0; i<cnt; ++i) {
			int start_idx = (start + primes[i] - 1) / primes[i];
			int j = max(start_idx,2) * primes[i] - start;
			for (; j<S; j+=primes[i])
				bl[j] = true;
		}
		if (k == 0)
			bl[0] = bl[1] = true;
		for (int i=0; i<S && start+i<=n; ++i)
			if (!bl[i]) {
			    int p = start + i;
                //printf("%d\n", start + i);
                int cur = p, cnt = 0;
                while (true) {
                    cnt += n / cur;
                    if (cur > n / p) {
                        break;
                    }
                    cur *= p;
                }
                cur = 1;
                for (int j = 0; j < 4; ++j) {
                    ans[j] += cur * cnt;
                    cur *= p;
                }
			}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    get_all_primes();
    int res = 0;
    reverse(ans, ans + 4);
    for (int i = 0; i < 4; ++i) {
        int k = 1;
        cin >> k;
        res += ans[i] * k;
    }
    long long ANS = res;
    if (ANS < 0) {
        ANS += (1LL << 32);
    }
    cout << ANS << "\n";
    return 0;
}