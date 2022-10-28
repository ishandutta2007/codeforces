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
int ql, qr;
int a[N], s[2][N*4];

/*
Answer is the max of the consequtive pairs of 0 or 1.
Why? At each time, you could reduce the number of pair by at most one, also at least one (if there are still any), for both "0" and "1".
*/

void build_tree(int o, int L, int R)
{
    if(L==R)
    {
        return;
    }
    int mid = (L+R)>>1, j;
    build_tree(o<<1, L, mid);
    build_tree(o<<1|1, mid+1, R);
    if(a[mid] != a[mid+1])
    {
        for(j=0;j<=1;j++)
            s[j][o] = s[j][o<<1] + s[j][o<<1|1];
    }
    else
    {
        for(j=0;j<=1;j++)
            s[j][o] = s[j][o<<1] + s[j][o<<1|1];
        s[a[mid]][o]++;
    }
}

int ans, sum[2], now;

void Query(int o, int L, int R)
{
    
    if(ql <= L && R <= qr)
    {
        int j;
        for(j=0;j<=1;j++)
            sum[j] += s[j][o];
        if(now == a[L])
            sum[a[L]]++;
        now = a[R];
        return;
    }
    int mid=(L+R)>>1;
    if(ql <= mid)
        Query(o<<1, L, mid);
    if(qr > mid)
        Query(o<<1|1, mid+1, R);
}

char b[N];

int main()
{
    int n, q, i;
    cin >> n >> q;
    scanf("%s",b+1);
    for(i=1;i<=n;i++)
        a[i] = b[i] - '0';
    build_tree(1,1,n);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d", &ql, &qr);
        sum[0] = sum[1] = 0;
        now = -1;
        Query(1,1,n);
        ans = max(sum[0], sum[1]);
        printf("%d\n", ans+1);
    }
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);