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
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[N];
set<int> st;
int nxt[N],last[27],fir[27],sum[27];
string ans;
int main()
{
    int m,n,i,cnt=0,j,k,flag;
    cin>>m;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=m;i<=n;i++)
        st.insert(i);
    for(i=1;i<=n;i++)
    {
        s[i]-=96;
        sum[s[i]]++;
        nxt[last[s[i]]]=i;
        if(!last[s[i]])
            fir[s[i]]=i;
        last[s[i]]=i;
    }
    for(i=1;i<=26&&st.size();i++)
    {
        flag=1;
        cnt=0;
        for(j=fir[i];j;j=nxt[j])
        {
            //debug(j);
            if(*st.begin()<j)
            {
                //debug(i);
                flag=0;
                //break;
            }
            k=nxt[j];
            if(st.size())
            {
                if(!k||(st.lower_bound(k)!=st.begin())||!flag)
                {
                    cnt++;
                    while(!st.empty()&&st.lower_bound(j)!=st.end()&&*st.lower_bound(j)<=j+m-1)
                        st.erase(st.lower_bound(j));
                }
            }

            if(st.empty())
                break;
        }
        if(st.empty())
        {
            for(j=1;j<=cnt;j++)
                ans.push_back(i+96);
        }
        else
            for(j=1;j<=sum[i];j++)
                ans.push_back(i+96);
    }
    //return 0;
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/