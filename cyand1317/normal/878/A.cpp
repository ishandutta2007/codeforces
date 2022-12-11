#include <cstdio>
static const int MAXLG = 10;

int n;
int outcome[2];

int main()
{
    scanf("%d", &n);

    outcome[0] = 0;
    outcome[1] = (1 << MAXLG) - 1;

    char s[4];
    int operand;
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", s, &operand);
        switch (s[0]) {
            case '&': outcome[0] &= operand; outcome[1] &= operand; break;
            case '|': outcome[0] |= operand; outcome[1] |= operand; break;
            case '^': outcome[0] ^= operand; outcome[1] ^= operand; break;
            default: puts("> <");
        }
    }

    int and_operand = 0, or_operand = 0, xor_operand = 0;
    for (int i = 0; i < MAXLG; ++i) {
        int res = (((outcome[0] >> i) & 1) << 1) | ((outcome[1] >> i) & 1);
        switch (res) {
            case 0: break;
            case 1: and_operand |= (1 << i); break;
            case 2: and_operand |= (1 << i); xor_operand |= (1 << i); break;
            case 3: and_operand |= (1 << i); or_operand |= (1 << i); break;
        }
    }

    puts("3");
    printf("& %d\n", and_operand);
    printf("| %d\n", or_operand);
    printf("^ %d\n", xor_operand);

    return 0;
}