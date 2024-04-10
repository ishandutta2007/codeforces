#include <cstdio>

int main()
{
    int spec, winner, new_winner;
    int n;

    scanf("%d%d", &n, &winner);
    if (winner == 3) { puts("NO"); return 0; }
    spec = 6 - 3 - winner;

    for (int i = 1; i < n; ++i) {
        scanf("%d", &new_winner);
        if (new_winner == spec) { puts("NO"); return 0; }
        winner = new_winner;
        spec = 6 - spec - winner;
    }

    puts("YES"); return 0;
}