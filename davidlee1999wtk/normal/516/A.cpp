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
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[10][10],a[10];
char s[20];
int main()
{
    c[2][2]=1;
    c[3][3]=1;
    c[4][2]=2,c[4][3]=1;
    c[5][5]=1;
    c[6][3]=1,c[6][5]=1;
    c[7][7]=1;
    c[8][2]=3,c[8][7]=1;
    c[9][2]=1,c[9][3]=2,c[9][7]=1;
    int n,i,j;
    cin>>n;
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=9;j++)
            a[j]+=c[s[i]-48][j];
    }
    for(j=9;j;j--)
        while(a[j])
            printf("%d",j),a[j]--;
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);