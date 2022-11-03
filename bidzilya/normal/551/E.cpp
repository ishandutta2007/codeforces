#include <bits/stdc++.h>
using namespace std;

const int kBlockSize = 300;

int n;
vector<long long> a;
vector<long long> sums;
vector<unordered_set<long long> > sets;
int amount_of_blocks;
vector<int> block_left;
vector<int> block_right;
vector<int> block_index;

void Apply(int cur_block_index, int left, int right, long long add)
{
    sets[cur_block_index].clear();
    for (int i = block_left[cur_block_index]; i < block_right[cur_block_index]; ++i) {
        a[i] += sums[cur_block_index];
        if (i >= left && i < right) {
            a[i] += add;
        }
        sets[cur_block_index].insert(a[i]);
    }
    sums[cur_block_index] = 0;
}

void Construct()
{
    for (int i = 0; i * kBlockSize < n; ++i) {
        block_left.push_back(i * kBlockSize);
        block_right.push_back(min(n, (i + 1) * kBlockSize));
    }
    amount_of_blocks = block_left.size();
    sums.assign(amount_of_blocks, 0);
    sets.resize(amount_of_blocks);
    block_index.resize(n);
    for (int i = 0; i < amount_of_blocks; ++i) {
        for (int j = block_left[i]; j < block_right[i]; ++j) {
            block_index[j] = i;
            sets[i].insert(a[j]);
        }
    }
}

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    const int kN = 5e5;
    const int kQ = 5e4;
    cout << kN << " " << kQ << endl;
    for (int i = 0; i < kN; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < kQ / 2; ++i) {
        int l, r;
        l = rand() % kN + 1;
        r = rand() % kN + 1;
        if (l > r) {
            swap(l, r);
        }
        cout << 1 << " " << l << " " << r << " " << i << endl;
    }
    for (int i = 0; i < kQ / 2; ++i) {
        cout << 2 << " " << i << endl;
    }
    return 0;
    */
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int qs;

    scanf("%d%d", &n, &qs);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    Construct();

    for (; qs; --qs) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;
            for (int i = 0; i < amount_of_blocks; ++i) {
                int cl = max(l, block_left[i]);
                int cr = min(r, block_right[i]);

                if (cl < cr) {
                    if (cl == block_left[i] && cr == block_right[i]) {
                        sums[i] += x;
                    } else {
                        Apply(i, cl, cr, x);
                    }
                }
            }
        } else {
            int y;
            scanf("%d", &y);

            int min_block_index = -1;
            int max_block_index = -1;
            for (int i = 0; i < amount_of_blocks; ++i) {
                long long cy = y - sums[i];

                if (sets[i].find(cy) != sets[i].end()) {
                    if (min_block_index == -1) {
                        min_block_index = i;
                    }
                    max_block_index = i;
                }
            }
            if (min_block_index == -1) {
                printf("-1\n");
                continue;
            }
            int min_index = -1;
            int max_index = -1;
            for (int i = block_left[min_block_index]; i < block_right[min_block_index]; ++i) {
                if (a[i] == y - sums[min_block_index]) {
                    min_index = i;
                    break;
                }
            }
            for (int i = block_left[max_block_index]; i < block_right[max_block_index]; ++i) {
                if (a[i] == y - sums[max_block_index]) {
                    max_index = i;
                }
            }
            printf("%d\n", max_index - min_index);
        }
    }

    return 0;
}