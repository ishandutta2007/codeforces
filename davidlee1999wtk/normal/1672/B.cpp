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
#define N 200005
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
        scanf("%s", s+1);
        int n, flag = 1;
        n = strlen(s+1);
        int i, mx = 0, mn = 0;
        for(i=1;i<=n;i++)
        {
            if(s[i] == 'A')
            {
                mn = 1;
                mx ++;
            }
            else
            {
                if(mx == 0)
                {
                    flag = 0;
                }
                mx --;
                mn = 0;
            }
        }
        if(mn != 0)
            flag = 0;
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);