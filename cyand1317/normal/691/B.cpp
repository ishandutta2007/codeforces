#include <cstdio>
static const int MAXN = 1024;

int n;
char s[MAXN];

inline bool isalpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
inline bool mirror(char a, char b)
{
    switch (a) {
        case 'b': return b == 'd';
        case 'd': return b == 'b';
        case 'p': return b == 'q';
        case 'q': return b == 'p';
        case 'o': case 'v': case 'w': case 'x':
        case 'O': case 'V': case 'W': case 'X':
        case 'A': case 'H': case 'I': case 'M': case 'T': case 'U': case 'Y':
            return b == a;
        default: return false;
    }
}
inline bool s_palindrome()
{
    for (int i = 0; i < n; ++i)
        if (!mirror(s[i], s[n - i - 1])) return false;
    return true;
}

int main()
{
    n = 0;
    while (isalpha(s[n] = getchar())) ++n;
    puts(s_palindrome() ? "TAK" : "NIE");
    return 0;
}