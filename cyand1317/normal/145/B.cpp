#include <cstdio>

int a1, a2, a3, a4;

int main()
{
    scanf("%d%d%d%d", &a1, &a2, &a3, &a4);

    switch (a3 - a4) {
        case 0:     // a3 = a4, 474...474 or 747...747
            if (a1 < a3 || a2 < a4 || (a1 <= a3 && a2 <= a4)) { puts("-1"); break; }
            if (a1 > a3) {
                // (1) 474...474
                putchar('4');
                for (int i = 0; i < a1 - a3 - 1; ++i) putchar('4');
                for (int i = 0; i < a3 - 1; ++i) fputs("74", stdout);
                for (int i = 0; i < a2 - a3; ++i) putchar('7');
                puts("74");
            } else {
                // (2) 747...747
                putchar('7');
                for (int i = 0; i < a1 - a3; ++i) putchar('4');
                for (int i = 0; i < a3; ++i) fputs("47", stdout);
                for (int i = 0; i < a2 - a3 - 1; ++i) putchar('7');
                putchar('\n');
            }
            break;

        case +1:    // a3 = a4 + 1, 4747...47
            if (a1 < a3 || a2 < a3) { puts("-1"); break; }
            putchar('4');
            for (int i = 0; i < a1 - a3; ++i) putchar('4');
            putchar('7');
            for (int i = 0; i < a3 - 1; ++i) fputs("47", stdout);
            for (int i = 0; i < a2 - a3; ++i) putchar('7');
            putchar('\n');
            break;

        case -1:    // a4 = a3 + 1, 7474...74
            if (a1 < a4 || a2 < a4) { puts("-1"); break; }
            putchar('7');
            putchar('4');
            for (int i = 0; i < a1 - a4; ++i) putchar('4');
            for (int i = 0; i < a4 - 2; ++i) fputs("74", stdout);
            putchar('7');
            for (int i = 0; i < a2 - a4; ++i) putchar('7');
            putchar('4');
            putchar('\n');
            break;

        default: puts("-1"); break;
    }

    return 0;
}