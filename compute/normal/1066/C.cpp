#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int ltr[maxn];
void addl(int x)
{
    while(x<maxn)
    {
        ltr[x]++;
        x+=x&-x;
    }
}
int suml(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=ltr[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    int q;
    scanf("%d",&q);
    char op[10];
    int x;
    map<int,int> inf;
    int L=200001,R=L;
    memset(ltr,0,sizeof(ltr));
    while(q--)
    {
        scanf("%s%d",op,&x);
        if(op[0]=='L')
        {
            inf[x]=--L;
            addl(L);
        }
        else if(op[0]=='R')
        {
            inf[x]=++R;
            addl(R);
        }
        else{
            int ans=0;
            ans=min(suml(inf[x]-1),suml(maxn)-suml(inf[x]));
            printf("%d\n",ans);
        }
    }
}