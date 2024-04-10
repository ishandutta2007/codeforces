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
char s[11];
int main()
{
    int T, n, i;
    char mn;
    cin >> T;
    while(T--)
    {
        scanf("%s", s+1);
        n = strlen(s+1);
        if(n== 2)
            printf("%c\n", s[2]);
        else
        {
            mn = '9';
            for(i=1;i<=n;i++)
                mn = min(mn, s[i]);
            cout<<mn<<endl;
        }
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);