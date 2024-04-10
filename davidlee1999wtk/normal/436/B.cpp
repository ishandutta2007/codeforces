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
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m,k;
char s[2005][2005];
int sum[2005];
int main()
{
    int i,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            //cout<<s[i][j]<<endl;
            if(s[i][j]=='R')
                if(j+i-1<=m)
                    sum[j+i-1]++;
            if(s[i][j]=='L')
                if(j-i+1>0)
                    sum[j-i+1]++;
            if(s[i][j]=='U')
                if(i%2==1)
                    sum[j]++;
        }
    for(i=1;i<=m;i++)
        printf("%d ",sum[i]);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);