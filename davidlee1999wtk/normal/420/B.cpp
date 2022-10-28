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
#define INF 100000000
using namespace std;
typedef long long LL;
char t[100005][3];
int flag[100005],rel[100005];
int onl[100005],num[100005];
int main()
{
    int n,m,ans=0,i,now=0,chu=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%s",t[i]);
        scanf("%d",&num[i]);
    }
    for(i=1;i<=m;i++)
    {
        if(t[i][0]=='+')
        {
            if(i!=1&&num[i-1]!=num[i])
                flag[num[i]]=-1;
            if(now)
                flag[num[i]]=-1;
            else chu=num[i];
            onl[num[i]]=1; now++;
        }
        if(t[i][0]=='-')
        {
            if(i!=m)
                if(num[i+1]!=num[i])
                    flag[num[i]]=-1;
            if(onl[num[i]]) onl[num[i]]=0,now--;
            else
                flag[chu]=-1;
            if(now) flag[num[i]]=-1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(flag[i]!=-1)
            rel[++ans]=i;
    }
    cout<<ans<<endl;
    for(i=1;i<=ans;i++)
        printf("%d ",rel[i]);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);