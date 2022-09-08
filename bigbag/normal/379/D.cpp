#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_k = 55;

long long k, x, n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> x >> n >> m;
    for (int i = 'A'; i <= 'C'; ++i) {
        for (int j = 'A'; j <= 'C'; ++j) {
            for (int q = 'A'; q <= 'C'; ++q) {
                for (int p = 'A'; p <= 'C'; ++p) {
                    int aaa = 0, aaa1 = 0;
                    if (i == 'B' && j == 'B') {
                        aaa = 1;
                    }
                    if (q == 'B' && p == 'B') {
                        aaa1 = 1;
                    }
                    aaa = aaa1 = 0;
                    for (int cnt = aaa; cnt < 100; ++cnt) {
                        for (int cnt1 = aaa1; cnt1 < 100; ++cnt1) {
                            int first_let1 = i, last_let1 = j, first_let2 = q, last_let2 = p;
                            if (j == 'B') {
                                if (cnt != 0) {
                                    last_let1 = 'C';
                                } else {
                                    last_let1 = i;
                                }
                            }
                            if (i == 'B') {
                                if (cnt != 0) {
                                    first_let1 = 'A';
                                } else {
                                    first_let1 = i;
                                }
                            }
                            if (q == 'B') {
                                if (cnt1 != 0) {
                                    first_let2 = 'A';
                                } else {
                                    first_let2 = p;
                                }
                            }
                            if (p == 'B') {
                                if (cnt1 != 0) {
                                    last_let2 = 'C';
                                } else {
                                    last_let2 = q;
                                }
                            }
                            long long ac1 = cnt, ac2 = cnt1;
                            if (cnt == 0 && first_let1 == 'A' && last_let1 == 'C') {
                                ac1 = 1;
                            }
                            if (cnt1 == 0 && first_let2 == 'A' && last_let2 == 'C') {
                                ac2 = 1;
                            }
                            for (int ii = 2; ii < k; ++ii) {
                                long long ac3 = ac1 + ac2;
                                if (last_let1 == 'A' && first_let2 == 'C') {
                                    ++ac3;
                                }
                                int first_let3 = first_let1, last_let3 = last_let2;
                                first_let1 = first_let2;
                                last_let1 = last_let2;
                                first_let2 = first_let3;
                                last_let2 = last_let3;
                                ac1 = ac2;
                                ac2 = ac3;
                            }
                            int izm1 = 0, izm2 = 0, fff1 = 0, fff2 = 0;
                            if (j == 'B') {
                                fff1 = 1;
                            }
                            if (q == 'B') {
                                fff2 = 1;
                            }
                            if (i == 'B') {
                                ++izm1;
                            }
                            if (p == 'B') {
                                ++izm2;
                            }
                            first_let1 = i, last_let1 = j, first_let2 = q, last_let2 = p;
                            if (ac2 == x && cnt * 2 + 2 - izm1 - fff1 <= n  && cnt1 * 2 + 2 - izm2 - fff2 <= m) {
                                if (izm1 != 1) {
                                    printf("%c", first_let1);
                                }
                                for (int ii = 0; ii < cnt; ++ii) {
                                    cout << "AC";
                                }
                                for (int ii = cnt * 2 + 2 - izm1 - fff1; ii < n; ++ii) {
                                    cout << "Z";
                                }
                                if (fff1 != 1) {
                                    printf("%c\n", last_let1);
                                } else {
                                    cout << endl;
                                }

                                if (fff2 != 1) {
                                    printf("%c", first_let2);
                                }
                                for (int ii = 0; ii < cnt1; ++ii) {
                                    cout << "AC";
                                }
                                if (cnt1 == 0 && first_let2 == 'B') {
                                    if (izm2 != 1) {
                                        printf("%c", last_let2);
                                    }
                                    for (int ii = cnt1 * 2 + 2 - izm2 - fff2; ii < m; ++ii) {
                                        cout << "Z";
                                    }
                                } else {
                                    for (int ii = cnt1 * 2 + 2 - izm2 - fff2; ii < m; ++ii) {
                                        cout << "Z";
                                    }
                                    if (izm2 != 1) {
                                        printf("%c\n", last_let2);
                                    }
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!" << endl;
    return 0;
}