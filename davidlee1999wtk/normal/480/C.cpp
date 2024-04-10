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
#define INF 100000000
#define fi first
#define se second
#define P 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
LL dp[5005][5005];
LL c[5005];
/*
void upd(int &x,int y)
{
    x+=y;
    if(x>=P)
        x-=P;
}


void Insert(int o,int L,int R)
{
    if(ql<=L&&R<=qr)
    {
        upd(c[o],qw);
        return;
    }
    int mid=(L+R)>>1;
    if(ql<=mid)
        Insert(o<<1,L,mid);
    if(qr>mid)
        Insert(o<<1|1,mid+1,R);
}

inline void push_down(int o)
{
    upd(c[o<<1],c[o]);
    upd(c[o<<1|1],c[o]);
    c[o]=0;
}
void bl(int o,int L,int R,int *f)
{
    if(L==R)
    {
        f[L]=c[o];
        c[o]=0;
        return;
    }
    push_down(o);
    int mid=(L+R)>>1;
    bl(o<<1,L,mid,f);
    bl(o<<1|1,mid+1,R,f);
}
*/
int main()
{
    int a,b,k,i,j,l;
    cin>>n>>a>>b>>k;
    if(a>b)
        a=n-a+1,b=n-b+1;
        dp[0][a]=1;
        for(i=a-1;i;i--)
            dp[0][i]=(dp[0][i]+dp[0][i+1])%P;
        for(i=0;i<k;i++)
        {
            for(j=b-1;j;j--)
            {
                l=(b+j+1)>>1;
                l=max(l,1);
                dp[i+1][j]=(dp[i][1]-dp[i][l]-dp[i][j]+dp[i][j+1]+P+P)%P;
                dp[i+1][j]=(dp[i+1][j]+dp[i+1][j+1])%P;
            }
        }
        cout<<dp[k][1]<<endl;

}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
// 5000 1 5000 5000