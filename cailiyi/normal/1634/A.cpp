#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100
using namespace std;
int T,n,k;
char s[N+5];
inline bool check()
{
    for(int i=0;i<<1<n;++i)
        if(s[i]!=s[n-i-1]) return 0;
    return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        if(!k || check()) puts("1");
        else puts("2");
    }
    return 0;
}