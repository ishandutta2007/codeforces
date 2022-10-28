#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[100005],tmp[2];
int k,L,R,ql[505],qr[505],now,c[100005],l[505],r[505],sum[28],t=0;
char le[505];
int main()
{
    int n,i,j;
    LL ans=0;
    scanf("%s",s+1);
    cin>>k>>L>>R;
    n=strlen(s+1);
    for(i=1;i<=n;i++)
        s[i]-=97;
    for(i=1;i<=k;i++)
    {
        cin>>le[i],le[i]-=97;
        scanf("%d%d",&ql[i],&qr[i]);
        if(ql[i]==0) t++;
    }
    for(i=1;i<=n;i++)
    {
        sum[s[i]]++;
        c[i]=t;
        if(L<=c[i]&&c[i]<=R) now++;
        for(j=1;j<=k;j++)
            if(le[j]==s[i])
            {
                if(sum[s[i]]>=ql[j]&&ql[j]!=0)
                    while(1)
                    {
                        c[++l[j]]++;
                        if(c[l[j]]==L)
                            now++;
                        else if(c[l[j]]==R+1)
                            now--;
                        if(s[l[j]]==s[i]) break;
                    }
                if(sum[s[i]]>qr[j])
                    while(1)
                    {
                        c[++r[j]]--;
                        if(c[r[j]]==L-1)
                            now--;
                        else if(c[r[j]]==R)
                            now++;
                        if(s[r[j]]==s[i]) break;
                    }
            }
        ans+=now;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
decddddd
8 2 3
e 0 1
e 0 3
c 0 1
c 0 0
c 0 0
a 0 0
c 1 1
d 0 4

bcbbb
3 1 2
a 0 1
c 0 2
c 0 0
*/