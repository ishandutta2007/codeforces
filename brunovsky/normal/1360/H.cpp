#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    while (T--) {
        int N, M;
        cin >> N >> M;
        set<long> arr;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            arr.insert(stoll(s, 0, 2));
        }

        long ans;

        if (M <= 8) {
            vector<long> all(1 << M); // ....
            iota(begin(all), end(all), 0);

            all.erase(remove_if(begin(all), end(all),
                                [&](long x) { return arr.count(x); }),
                      end(all));

            int A = all.size();
            assert(A == (1 << M) - N);
            ans = all[(A - 1) / 2];
        } else {
            long median = (1LL << (M - 1)) - 1;

            int delta = 1;
            set<long> below, above;
            for (long n = median - 1; n >= median - N - 2; n--)
                below.insert(n);
            for (long n = median + 1; n <= median + N + 2; n++)
                above.insert(n);

            for (long x : arr) {
                // printf("process x=%ld, median=%ld, delta=%d\n", x, median, delta);
                if (x == median) {
                    if (delta == 0) {
                        do {
                            median--;
                        } while (!below.count(median));
                        below.erase(median);
                        delta++;
                    } else {
                        do {
                            median++;
                        } while (!above.count(median));
                        above.erase(median);
                        delta--;
                    }
                } else if (x < median) {
                    below.erase(x);
                    if (delta == 0) {
                        delta = 1;
                    } else {
                        below.insert(median);
                        do {
                            median++;
                        } while (!above.count(median));
                        above.erase(median);
                        delta = 0;
                    }
                } else {
                    above.erase(x);
                    if (delta == 1) {
                        delta = 0;
                    } else {
                        above.insert(median);
                        do {
                            median--;
                        } while (!below.count(median));
                        below.erase(median);
                        delta = 1;
                    }
                }
            }
            // printf("donesies, median=%ld\n", median);
            ans = median;
        }

        string s(M, '0');
        for (int b = 0; b < M; b++) {
            if ((ans >> b) & 1) {
                s[M - b - 1] = '1';
            }
        }
        cout << s << endl;
    }
    return 0;
}