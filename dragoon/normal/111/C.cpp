#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m, L;
int DP[42][1<<6][1<<6], cnt[1<<6];

int dp(int at, int pmask, int cmask)
{
    if(at==m)
    {
        if(cmask==L) return 0;
        else return n*m;
    }

    int &ret = DP[at][pmask][cmask], i, now, cur;
    if(ret!=-1) return ret;

    ret = n*m;
    for(i=0;i<=L;i++)
    {
        cur = (pmask | i | (i<<1) | (i>>1) ) & L;
        if( (cmask | i)==L)
        {
            now = cnt[i] + dp(at+1,i, cur);
            if(now<ret) ret = now;
        }
    }

    return ret;
}

int main()
{
    int i;
    
    scanf("%d%d",&n,&m);

    memset(DP,-1,sizeof(DP));

    if(n>m) swap(n,m);

    L = (1<<n)-1;

    cnt[0]=0;
    for(i=1;i<=L;i++)
        cnt[i] = cnt[i>>1] + (i&1);

    printf("%d\n",n*m-dp(0,0,L));

    return 0;
}