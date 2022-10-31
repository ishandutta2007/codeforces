#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
char s[110000];
char t[110000];
int n,q;
bitset<110000>f[27],ans;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)f[s[i]-'a'][i]=1;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int way;
        scanf("%d",&way);
        if(way==1)
        {
            int x;
            char tmp[4];
            scanf("%d%s",&x,tmp);
            f[s[x]-'a'][x]=0;
            s[x]=tmp[0];
            f[s[x]-'a'][x]=1;
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            scanf("%s",t+1);
            int len=strlen(t+1);
            r=r-len+1;
            if(r<l)
            {
                puts("0");
                continue;
            }
            ans.reset();
            ans=~ans;
            for(int i=1;i<=len;i++)ans&=(f[t[i]-'a']>>(i-1));
            ans>>=l;
            int sum=ans.count();
            ans>>=(r-l+1);
            sum-=ans.count();
            printf("%d\n",sum);
        }
    }
}