#include <bits/stdc++.h>
using namespace std;

const int kMaxAmountOfBits = 250;
const int kMaxAmountOfSteps = 210;
const int kMaxAmountOfBitsInPrefix = 8;
const int kMaxAmountOfOnes = 50;
const int kPrefixMod = (1 << kMaxAmountOfBitsInPrefix);

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

double ans[2][kMaxAmountOfBits][kPrefixMod][kMaxAmountOfOnes];
int cur_ptr;

inline int GetAmountOfZerosInPrefix(int x)
{
    int res = 0;
    while (x > 0 && (x & 1) == 0) {
        x >>= 1;
        ++res;
    }
    return res;
}

int amount_of_ones_in_prefix[kPrefixMod];

inline int GetAmountOfOnesInPrefix(int x)
{
    int res = 0;
    while (x > 0 && (x & 1) == 1) {
        ++res;
        x >>= 1;
    }
    return res;
}

int main()
{
    for (int i = 0; i < kPrefixMod; ++i) {
        amount_of_ones_in_prefix[i] = GetAmountOfOnesInPrefix(i);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, k;
    double prob;

    cin >> x >> k;
    {
        int p;
        cin >> p;
        prob = p / 100.0;
    }

    double neg_prob = 1.0 - prob;

    const double kEps = 1e-15;

    cur_ptr = 0;
    ans[cur_ptr][GetAmountOfZerosInPrefix(x)][x % kPrefixMod][GetAmountOfOnesInPrefix(x >> kMaxAmountOfBitsInPrefix)] = 1.0;
    for (int i = 1; i <= k; ++i) {
        int nxt_ptr = 1 - cur_ptr;
        for (int amount = 0; amount < kMaxAmountOfBits; ++amount) {
            for (int prefix = 0; prefix < kPrefixMod; ++prefix) {
                for (int amount_of_ones = 0; amount_of_ones < kMaxAmountOfOnes; ++amount_of_ones) {
                    ans[nxt_ptr][amount][prefix][amount_of_ones] = 0.0;
                }
            }
        }
        for (int amount = 0; amount < kMaxAmountOfBits; ++amount) {
            for (int prefix = 0; prefix < kPrefixMod; ++prefix) {
                for (int amount_of_ones = 0; amount_of_ones < kMaxAmountOfOnes; ++amount_of_ones) {
                    if (ans[cur_ptr][amount][prefix][amount_of_ones] < kEps) {
                        continue;
                    }
                    {
                        int new_amount = amount + 1;
                        int new_prefix = (prefix * 2) % kPrefixMod;
                        int new_amount_of_ones;
                        if (GetBit(prefix, kMaxAmountOfBitsInPrefix - 1)) {
                            new_amount_of_ones = amount_of_ones + 1;
                        } else {
                            new_amount_of_ones = 0;
                        }
                        ans[nxt_ptr][new_amount][new_prefix][new_amount_of_ones] +=
                            ans[cur_ptr][amount][prefix][amount_of_ones] * prob;
                    }
                    {
                        int new_prefix = prefix + 1;
                        if (new_prefix == kPrefixMod) {
                            new_prefix = 0;
                        }
                        int new_amount;
                        if (new_prefix != 0) {
                            new_amount = amount_of_ones_in_prefix[prefix];
                        } else {
                            new_amount = amount_of_ones_in_prefix[prefix] + amount_of_ones;
                        }
                        int new_amount_of_ones;
                        if (new_prefix != 0) {
                            new_amount_of_ones = amount_of_ones;
                        } else {
                            if (amount_of_ones == 0) {
                                new_amount_of_ones = 1;
                            } else {
                                new_amount_of_ones = 0;
                            }
                        }
                        ans[nxt_ptr][new_amount][new_prefix][new_amount_of_ones] +=
                            ans[cur_ptr][amount][prefix][amount_of_ones] * neg_prob;
                    }
                }
            }
        }
        swap(cur_ptr, nxt_ptr);
    }

    double answer = 0.0;
    for (int amount = 0; amount < kMaxAmountOfBits; ++amount) {
        double cur_ans = 0.0;
        for (int prefix = 0; prefix < kPrefixMod; ++prefix) {
            for (int amount_of_ones = 0; amount_of_ones < kMaxAmountOfOnes; ++amount_of_ones) {
                cur_ans += ans[cur_ptr][amount][prefix][amount_of_ones];
            }
        }
        answer += amount * cur_ans;
    }

    cout << fixed << setprecision(15) << answer << endl;

    return 0;
}