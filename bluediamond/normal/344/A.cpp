#include <cstdio>
using namespace std;

const int NMAX = 100010;

int N, Ans;
char S[NMAX][2];

int main()
{

    scanf("%i\n", &N);
    for(int i = 1; i <= N; ++ i)
        gets(S[i]);

    for(int i = 2; i <= N; ++ i)
        if(S[i][0] == S[i - 1][1])
            Ans ++;

    printf("%i\n", Ans + 1);
}