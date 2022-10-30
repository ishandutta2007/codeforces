#include <set>
#include <map>
#include <cstdio>
using namespace std;
map<int,int> SG;
map<int,int> masks;
int N;
int sg(int num)
{
    set<int> S;
    if(SG.count(num))return SG[num];
    for(int bit=0;;bit++)
    {
        if(!(num>>bit))break;
        int a=(num>>(bit+1));
        int b=num&((1<<(bit))-1);
        S.insert(sg(a|b));
    }
    int f=0;
    while(S.count(f))f++;
    return SG[num]=f;
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        int val;
        scanf("%d",&val);
        for(int j=2;1LL*j*j<=val;j++)
        {
            if(val%j==0)
            {
                int e=0;
                while(val%j==0)
                {
                    val/=j;
                    e++;
                }
                masks[j]|=(1<<(e-1));
            }
        }
        if(val>1)masks[val]|=1;
    }
    int xo=0;
    for(auto it:masks)
    {
        xo^=sg(it.second);
    }
    fputs(xo==0 ? "Arpa":"Mojtaba",stdout);
    return 0;
}