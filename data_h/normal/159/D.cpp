#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAXN = 3000;
long long s[MAXN], t[MAXN], Ans, sum;
int N;
char str[MAXN];

void Init()
{
    scanf("%s",str + 1);
    N = strlen(str + 1);
}

void Work()
{
    for(int i = 1;i <= N;i++)
    {
        int len = 0;
        while(i - len >= 1 && i + len <= N)
        {
            if (str[i - len] != str[i + len])
                break;
            s[i - len]++, t[i + len]++;
            len++;
        }
        len = 1;
        while(i - len >= 1 && i + len - 1 <= N)
        {
            if (str[i - len] != str[i + len - 1])
                break;
            s[i - len]++, t[i + len - 1]++;
            len++;
        }
    }
    for(int i = N;i >= 1;i--)
    {
        Ans += sum * t[i];
        sum += s[i];
    }
    printf("%I64d\n",Ans);
}

int main()
{
    Init();
    Work();
    return 0;
}