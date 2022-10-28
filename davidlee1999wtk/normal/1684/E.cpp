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
int a[N];
int main()
{
    int T, i;
    cin >> T;
    while(T--)
    {
        int n, k, mex=0, dif = 0, mov = 0;
        cin >> n >> k;
        mov = k;
        map<int, int> mp;
        //for(i=0;i<=n;i++)
            //vis[i] = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]] ++;
            //if(a < n)
                //vis[a] = 1;
        }
        for(i=0;i<n;i++)
        {
            if(!mp[i])
            {
                if(!k)
                {
                    mex = i;
                    break;
                }
                else
                {
                    k--;
                    //mov ++;
                }
            }
        }
        if(i==n)
            mex = n;
        //debug(mex);
        vector<int> b;
        for(i=1;i<=n;i++)
        {
            if(a[i] >= mex && mp[a[i]])
            {
                dif ++;
                b.push_back(mp[a[i]]);
                mp[a[i]] = 0;
            }
        }
        sort(b.begin(), b.end());
        for(auto x : b)
        {
            if(mov >= x)
            {
                mov -= x;
                dif --;
            }
            else
                break;
        }
        cout<<dif<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);