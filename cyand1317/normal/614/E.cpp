#include <cstdio>
static const int MAXN = 27;
static const int MAXS = 100006;

int n, a[MAXN], a_sum = 0;

inline bool check(int num_blocks)
{
    int block_sz = a_sum / num_blocks;
    if (num_blocks % 2 == 0) {
        for (int i = 0; i < n; ++i) if (a[i] % num_blocks != 0) return false;
    } else {
        bool extra_used = (block_sz % 2 == 0 ? true : false);
        for (int i = 0; i < n; ++i)
            if (a[i] % (num_blocks * 2) != 0) {
                if (a[i] % num_blocks == 0 && !extra_used) extra_used = true;
                else return false;
            }
    }
    return true;
}

inline void print_answer(int num_blocks)
{
    printf("%d\n", num_blocks);
    static char s[MAXS] = { 0 };
    int block_sz = a_sum / num_blocks;
    int letter = 0, fill = 0;
    if (num_blocks % 2 == 0) {
        while (fill < block_sz) {
            while (a[letter] == 0) ++letter;
            for (int i = 0; i < num_blocks; ++i)
                s[i * block_sz + ((i & 1) ? fill : (block_sz - 1 - fill))] = 'a' + letter;
            a[letter] -= num_blocks;
            fill++;
        }
    } else {
        bool acute_filled = (block_sz % 2 == 0 ? true : false);
        while (fill < block_sz / 2 || !acute_filled) {
            while (a[letter] == 0) ++letter;
            if (a[letter] % (num_blocks * 2) != 0) {
                for (int i = 0; i < num_blocks; ++i)
                    s[i * block_sz + (block_sz / 2)] = 'a' + letter;
                a[letter] -= num_blocks;
                acute_filled = true;
            } else {
                for (int i = 0; i < num_blocks; ++i)
                    s[i * block_sz + fill] = s[i * block_sz + (block_sz - 1 - fill)] = 'a' + letter;
                a[letter] -= num_blocks * 2;
                fill++;
            }
        }
    }
    puts(s);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); a_sum += a[i];
    }

    int i = 1;
    for (; i * i <= a_sum; ++i)
        if (a_sum % i == 0 && check(a_sum / i)) { print_answer(a_sum / i); return 0; }
    for (; i >= 1; --i)
        if (a_sum % i == 0 && check(i)) { print_answer(i); return 0; }

    //print_answer(0);
    printf("0\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a[i]; ++j) putchar('a' + i);
    putchar('\n');
    return 0;
}