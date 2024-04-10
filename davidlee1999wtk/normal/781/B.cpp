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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 1005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Team
{
    int num;
    string fir,sec;
}t[N];
map<string,int> mp;
bool cmp(Team a,Team b)
{
    return MP(a.fir,a.sec)<MP(b.fir,b.sec);
}
int vis[N];
string ans[N];
int main()
{
    int n,i,j,cnt=0,flag;
    string s1,s2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        t[i].fir=s1.substr(0,3);
        t[i].sec=s1.substr(0,2)+s2.substr(0,1);
        t[i].num=i;
    }
    sort(t+1,t+1+n,cmp);
    for(i=1;i<=n;i++)
    {
        if(t[i].fir==t[i-1].fir||t[i].fir==t[i+1].fir)
        {
            if(!mp[t[i].sec])
            {
                mp[t[i].sec]=1;
                ans[t[i].num]=t[i].sec;
                vis[i]=1;
                cnt++;
            }
            else
            {
                printf("NO\n");
                return 0;
            }

        }
    }
    for(j=1;j<=n&&cnt!=n;j++)
    {
        flag=0;
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(mp[t[i].fir]&&mp[t[i].sec])
                {
                    printf("NO\n");
                    return 0;
                }
                if(mp[t[i].fir])
                {
                    mp[t[i].sec]=1;
                    ans[t[i].num]=t[i].sec;
                    vis[i]=1;
                    cnt++;
                    flag=1;
                }
                else if(mp[t[i].sec])
                {
                    mp[t[i].fir]=1;
                    ans[t[i].num]=t[i].fir;
                    vis[i]=1;
                    cnt++;
                    flag=1;
                }
            }
        }
        if(!flag)
            break;
    }
    for(i=1;i<=n;i++)
        if(!vis[i])
        {
            mp[t[i].fir]=1;
            ans[t[i].num]=t[i].fir;
            vis[i]=1;
            cnt++;
            flag=1;
        }
    printf("YES\n");
    for(i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/