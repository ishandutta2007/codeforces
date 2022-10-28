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
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 105
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N], b[N], c[N], n, m, ok[N][N], loc_hr[N];
bool dp(vector<int> hr, vector<int> hp, vector<int> &ans, vector<int> st)
{
    int z = hr.size(), i, x;
    if(z == 0)
        return 1;
    //debug(z);
    vector<int> pre(z+1), vis(z+1), add_ans;
    queue<int> q;
    for(i=0;i<z;i++)
        if(st[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i=x+1;i<z;i++)
            if(!vis[i] && ok[i][x])
            {
                q.push(i);
                vis[i] = 1;
                pre[i] = x;
            }
    }
    if(!vis[z-1])
        return 0;
    else
    {
        for(i=0;i<z;i++)
            vis[i] = 0;
        int x = z-1;
        while(1)
        {
            //debug(x);
            add_ans.push_back(x);
            vis[x] = 1;
            if(st[x])
                break;
            else
                x = pre[x];
        }
        reverse(add_ans.begin(), add_ans.end());
        for(i=0;i<z;i++)
            if(!vis[i])
                add_ans.push_back(i);
        for(i=0;i<z;i++)
            ans.push_back(hr[add_ans[i]]);
        return 1;
    }
}

bool solve(int loc, int op)
{
    //debug(loc);
    //debug(op);
    int i, j, cnt, sum, flag = 1;
    vector<int> ans, hr, hp, st(N);
    //int st_i = loc-op, ed_i = 0, step = -1;
    auto ff = [&](int st_i, int ed_i, int step){
        cnt = 0, sum = 0;
        hr.clear(), hp.clear();
        memset(ok, 0, sizeof(ok));
        for(i=0;i<m;i++)
            st[i] = 0;
        for(i=st_i;i!=ed_i;i+=step)
        {
            if(c[i] == 0)
                ;
            else
            {
                ++cnt;
                hr.push_back(c[i]);
                hp.push_back(b[i]);
            }
        }
        for(j=cnt-1;j>=0;j--)
        {
            i = loc_hr[hr[j]];
            int cou = j;
            sum = b[i];
            //debug(i);
            for(i-=step;i+step!=st_i;i-=step)
            {
                if(c[i]==0)
                {
                    sum+=a[i];
                    if(sum < 0)
                        sum = -INF;
                }
                else
                {
                    cou--;
                    ok[j][cou] = sum >= 0?1:0;
                    //debug(ok[j][cou]);
                }
            }
            //debug(sum);

            st[j] = sum >= 0?1:0;
        }
        flag &= dp(hr, hp, ans, st);
        return hr.size();
    };

    int sz;
    sz = ff(loc-op, 0, -1);
    if(sz == 0)
        return 0;
    ff(loc+(op^1), n+1, 1);

    if(flag)
    {
        cout<<loc<<endl;
        for(auto x:ans)
            printf("%d ", x);
        return 1;
    }
    else
        return 0;
}

int main()
{
    int i, j, h, loc;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d", &loc, &h);
        b[loc] = h;
        c[loc] = i;
        loc_hr[i] = loc;
    }
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(i=1;i<=n;i++)
        if(solve(i, 0) || solve(i, 1))
        {
            break;
        }
    if(i>n)
        printf("-1\n");
    return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*
3 1
2 100
-5000 0 -5000
*/