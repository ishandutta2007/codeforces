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
#define INF 1000000000
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,du[30],k;
vector<int> G[30];
char s[105][105];
char ans[30];
void topo()
{
    queue<int> q;
    int i,len,x;
    for(i=0;i<26;i++)
        if(du[i]==0)
            q.push(i);
    while(!q.empty())
    {
        x=q.front(),q.pop();
        ans[++k]=x+97;
        len=G[x].size();
        for(i=0;i<len;i++)
        {
            du[G[x][i]]--;
            if(du[G[x][i]]==0)
                q.push(G[x][i]);
        }
    }
}
int main()
{
    int i,l1,j,l2;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(i=1;i<n;i++)
    {
        l1=strlen(s[i]+1);
        l2=strlen(s[i+1]+1);
        for(j=1;j<=min(l1,l2);j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                G[s[i][j]-97].push_back(s[i+1][j]-97);
                du[s[i+1][j]-97]++;
                break;
            }
        }
        if(j==min(l1,l2)+1)
            if(l1>l2)
            {
                printf("Impossible\n");
                return 0;
            }
    }
    topo();
    if(k==26)
        for(i=1;i<=26;i++)
            printf("%c",ans[i]);
    else printf("Impossible\n");
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);