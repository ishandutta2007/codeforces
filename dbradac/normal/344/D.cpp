#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 100100;

char s[MAX], *p;
stack <char> S;

int main()
{
    scanf("%s", s);

    for (p=s; *p; p++) {
        if (!S.empty() && S.top() == *p)
            S.pop();
        else
            S.push(*p);
    }

    if (S.empty())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}