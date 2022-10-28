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
int a[N], ql, qr, sum[N*4], ans;
void build_tree(int o, int L, int R)
{
    if(L == R)
    {
        sum[o] = 1;
        return;
    }
    int mid = (L+R) >> 1;
    build_tree(o << 1, L, mid);
    build_tree(o << 1 | 1, mid+1, R);
    sum[o] = sum[o<<1] + sum[o<<1 | 1];
}

void update(int o, int L, int R)
{
    if(L== R)
    {
        sum[o] = a[L];
        return;
    }
    int mid = (L+R) >> 1;
    if(ql <= mid)
    {
        update(o << 1, L, mid);
    }
    else
        update(o << 1 | 1, mid+1, R);
    sum[o] = sum[o<<1] + sum[o<<1 |1];
}

void query(int o, int L, int R)
{
    if(L >= ql && R <= qr)
    {
        ans += sum[o];
        return;
    }
    int mid = (L+R) >> 1;
    if(ql <= mid)
    {
        query(o << 1, L, mid);
    }
    if(qr >= mid+1)
        query(o<<1|1, mid+1, R);
}

int main()
{
    int n, q, now_l = 1, i, now_r, flip = 0;
    cin >> n >> q;
    now_r = n;
    for (i=1;i<=n;i++)
        a[i] = 1;
    build_tree(1,1,n);
    while(q--)
    {
        int op, p;
        scanf("%d", &op);
        if(op == 1)
        {
            scanf("%d", &p);
            if(flip == 1 && (now_r - now_l + 1 < p*2))
                flip = 0, p = now_r - now_l + 1 - p;
            if(flip == 0 && (now_r - now_l + 1 < p*2)) // Flip!
            {
                flip = 1;
                p = now_r - now_l + 1 - p;
            }
            //debug(p);

            if(flip == 0 && (now_r - now_l + 1 >= p*2))
            {
                //debug(p);
                for(int j = now_l; j < now_l + p; j++)
                {
                    a[now_l + p*2 - (j-now_l+1)] += a[j];
                    //debug(now_l + p*2 - (j-now_l+1));
                    ql = now_l + p*2 - (j-now_l+1);
                    update(1, 1, n);
                }
                now_l += p;
            }
            else if (flip == 1 && (now_r - now_l + 1 >= p*2))
            {
                for(int j = now_r; j > now_r - p; j--)
                {
                    a[now_r - p*2 + (now_r - j+1)] += a[j];
                    //debug(now_l + p*2 - (j-now_l+1));
                    ql = now_r - p*2 + (now_r - j+1);
                    update(1, 1, n);
                }
                now_r -= p;
            }
            else{
                debug("WRONG!");
                while(1);
            }
        }
        else
        {
            int l, r;
            scanf("%d%d",&l, &r);
            if(flip == 0)
            {
                ql = l + now_l;
                qr = r + now_l - 1;
            }
            else
            {
                qr = now_r - l;
                ql = now_r - r + 1;
            }
            //ql = max(ql, now_l);
            //qr = min(qr, now_r);
            ans = 0;
            query(1,1,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
// davidlee1999WTK 2021/
// srO myk Orz
//ios::sync_with_stdio(false);