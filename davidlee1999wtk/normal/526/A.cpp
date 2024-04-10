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
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[1005];
int main()
{
    int n,i,d,j;
    cin>>n;
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
        for(d=1;d<=n;d++)
        {
            for(j=0;j<5;j++)
                if(s[i+j*d]!='*')
                    break;
            if(j==5)
            {
                //debug(i);
                printf("yes\n");
                return 0;
            }
        }
    printf("no\n");
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//A. King of Thieves