#include <cstdio>
#include <cstring>

inline int weekday_id(const char *s) {
    if (!strcmp(s, "monday")) return 0;
    else if (!strcmp(s, "tuesday")) return 1;
    else if (!strcmp(s, "wednesday")) return 2;
    else if (!strcmp(s, "thursday")) return 3;
    else if (!strcmp(s, "friday")) return 4;
    else if (!strcmp(s, "saturday")) return 5;
    else return 6;
}

int main()
{
    char s[64], t[64];
    gets(s);
    gets(t);
    int a = weekday_id(s);
    int b = weekday_id(t);

    switch ((b - a + 7) % 7) {
        case 0: case 2: case 3: puts("YES"); break;
        default: puts("NO"); break;
    }

    return 0;
}