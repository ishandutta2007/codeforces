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
char s[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        scanf("%s", s+1);
        int i, flag = 0;
        for(i=1;i<n;i++)
        {
            //debug(i);
            if(s[i+1] > s[i])
                break;
            else if(s[i+1] < s[i])
                flag = 1;
            else
            {
                if(flag == 0)
                    break;
            }
        }
        int m = i;
        //debug(m);
        for(i=1;i<=m;i++)
            printf("%c", s[i]);
        for(i=m;i;i--)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);