#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
long long K, a[2000000];
struct node
{
    long long a, b;
}block[200000];
int tot = 0;

void Init()
{
    scanf("%d %I64d",&N,&K);
    for(int i = 1;i <= N;i++)
        scanf("%I64d",&a[i]);
    sort(a + 1,a + N + 1);
    for(int i = 1;i <= N;i++)
    {
        int j;
        for(j = i;j <= N && a[j] == a[i];j++);
        j--;
        block[++tot] = (node){a[i],j - i + 1};
        i = j;
    }
}

void Work()
{
    for(int i = 1;i <= tot;i++)
    {
        if (block[i].b * N < K)
            K -= block[i].b * N;
        else
        {
            long long p = block[i].b;
            printf("%I64d %I64d",block[i].a,a[(K - 1) / p + 1]);
            break;
        }
    }
}

int main()
{
    Init();
    Work();
    return 0;
}