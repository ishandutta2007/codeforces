#include <cstdio>
static const int MAXN = 500004;

int n;
int a[MAXN];
bool qwq[MAXN] = { false }; // Unstablility of elements

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i < n - 1; ++i) {
        qwq[i] = (a[i - 1] ^ a[i]) && (a[i] ^ a[i + 1]);
    }

    int longest_qwq = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && !qwq[j]) ++j;
        i = j;
        while (j < n && qwq[j]) ++j;
        if (longest_qwq < j - i) longest_qwq = j - i;
        // Update the sequence
        if ((j - i) % 2 == 0) {
            for (int k = i, p = j - 1; k < p; ++k, --p) {
                a[k] = a[i - 1]; a[p] = a[j];
            }
        } else {
            for (int k = i; k < j; ++k) a[k] = a[i - 1];
        }
    }

    printf("%d\n", (longest_qwq + 1) / 2);
    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}