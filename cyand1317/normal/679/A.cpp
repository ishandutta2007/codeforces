#include <cstdio>
#include <cstring>

static const int queries[20] = {
     2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47,  4,  9, 25, 49, 66
};
bool not_prime[103] = { false };
int results[103];

int main()
{
    for (int i = 2; i <= 100; ++i) {
        for (int j = 0; j < 20; ++j)
            if (i % queries[j] == 0) results[i] |= (1 << j);
    }
    for (int i = 2; i <= 100; ++i) if (!not_prime[i]) {
        for (int j = i + i; j <= 100; j += i) not_prime[j] = true;
    }
    for (int i = 2; i < 100; ++i)
        for (int j = i + 1; j <= 100; ++j)
            if (results[i] == results[j] && not_prime[i] ^ not_prime[j]) {
                printf("nyan > <\n"); return 0;
            }

    char s[16];
    int returned = 0;
    for (int i = 0; i < 20; ++i) {
        printf("%d\n", queries[i]); fflush(stdout);
        gets(s);
        if (strcmp(s, "yes") == 0)
            returned |= (1 << i);
    }
    for (int i = 2; i <= 100; ++i) if (returned == results[i]) {
        puts(not_prime[i] ? "composite" : "prime"); break;
    }
    return 0;
}