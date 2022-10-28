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
#define P 1000000007
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
#define qi q[num[i]]
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Row
{
    int l, r, b;
    Row(int L, int R, int B):l(L), r(R), b(B) {}
    bool operator < (const Row &t) const
    {
        return r > t.r;
    }
};
int cf[N];
vector<Row> ce[2];

int num[N]; // number for priority queue
int offset[N]; 
int solve(vector<Row> ce, int n)
{
    int m = ce.size(), i, j; // we have a matrix of size m * n
    int rank = 0;
    priority_queue<Row> q[N];
    memset(offset, 0, sizeof(offset));
    for(i=1;i<=n;i++)
        num[i] = i;
    for(i=0;i<m;i++)
        q[ce[i].l].push(ce[i]);

    // guassian elemination
    for(i=1;i<=n;i++)
    {
        if(qi.empty())
            continue;
        rank ++;

        Row tr = qi.top();
        qi.pop();
        //debug(i);
        //debug(tr.l);
        //debug(tr.r);
        while(!qi.empty() && qi.top().r == tr.r)
        {
            //debug(q[num[i]].top().r);
            if(qi.top().b != tr.b)
                return -1; // no solution.
            qi.pop();
        }

        int nl = tr.r + 1;
        if(!qi.empty())
        {
            //if(1)
            if(qi.size() <= q[num[nl]].size())
            {
                while(!qi.empty())
                {
                    Row er = qi.top();
                    qi.pop();
                    er.b ^= (tr.b ^ offset[nl]);
                    q[num[nl]].push(er);
                }
            }
            else
            {   
                while(!q[num[nl]].empty())
                {
                    Row er = q[num[nl]].top();
                    q[num[nl]].pop();
                    er.b ^= offset[nl] ^ tr.b;
                    qi.push(er);
                }
                offset[nl] = tr.b;
                num[nl] = num[i];
            }
        }
    }
    //debug(rank);
    return n - rank;
}

int main()
{
    int n, k, i, a, b, n_0, n_1;
    char c;
    int L, R, B;
    cin >> n >> k;
    n_0 = (n+1)/2;
    n_1 = n/2;
    cf[0] = 1;
    for(i=1;i<=n;i++)
    {
        cf[i] = cf[i-1] * 2 % P;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d%d %c", &a, &b, &c);
        if (c == 'x') 
            c = 0;
        else
            c = 1;
        if((a+b) % 2 == 0)
        {
            L = abs(a-b)/2 + 1;
            R = n_0 - abs(a+b - (n+1))/2;
            B = c;
            ce[0].push_back(Row(L, R, B));
        }
        else
        {
            L = abs(a-b)/2 + 1;
            R = n_1 - abs(a+b - (n+1))/2;
            B = c;
            ce[1].push_back(Row(L, R, B));
        }
    }
    int ans_0, ans_1;
    ans_0 = solve(ce[0], n_0);
    ans_1 = solve(ce[1], n_1);
    if (ans_0 == -1 || ans_1 == -1)
        cout << 0 << endl;
    else
        cout << LL(cf[ans_0]) * cf[ans_1] % P << endl;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);