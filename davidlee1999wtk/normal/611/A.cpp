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
char s[10];
int day[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int x,i,j,k;
    cin>>x;
    scanf("%s",s);
    scanf("%s",s);
    if(s[0]=='m')
    {
        if(x<=29)
            printf("12\n");
        else if(x==30)
            printf("11\n");
        else printf("7\n");
    }
    else
    {
        int ans=0;
        k=5;
        for(i=1;i<=12;i++)
            for(j=1;j<=day[i];j++)
            {
                if(k==x)
                    ans++;
                k++;
                if(k==8) k=1;
            }
        cout<<ans<<endl;
    }
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))