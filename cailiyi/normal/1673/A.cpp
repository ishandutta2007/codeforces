#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,sum,val;
char s[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s),sum=0;
        for(n=0;s[n];++n) sum+=s[n]-'a'+1;
        val=n&1?sum-(min(s[0],s[n-1])-'a'+1):sum;
        printf(val>sum-val?"Alice":"Bob");
        printf(" %d\n",abs(sum-(val<<1)));
    }
    return 0;
}