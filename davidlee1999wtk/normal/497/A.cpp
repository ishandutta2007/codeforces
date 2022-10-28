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
char s[1005][1005];
int rk[1005],trk[1005];
int main()
{
    int n,m,i,j,ans=0,flag;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(j=1;j<=m;j++)
    {
        flag=0;
        trk[1]=0;
        for(i=1;i<n;i++)
        {
            if(rk[i]<rk[i+1])
            {
                trk[i+1]=trk[i]+1;
                continue;
            }
            else
            {
                if(s[i][j]>s[i+1][j])
                {
                    ans++;
                    //printf("j=%d i=%d\n",j,i);
                    flag=1;
                    break;
                }
                else if(s[i][j]<s[i+1][j])
                    trk[i+1]=trk[i]+1;
                else trk[i+1]=trk[i];
            }
        }
        if(!flag)
            for(i=1;i<=n;i++)
                rk[i]=trk[i];
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);