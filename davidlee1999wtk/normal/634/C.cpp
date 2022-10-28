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
int c1[N],c2[N];
int a[N],n,k,A,B,q;
inline void upd(int *c,int i,int w)
{
    for(;i<=n;i+=(i&-i))
        c[i]+=w;
}

inline int get(int *c,int i)
{
    int sum=0;
    for(;i;i-=(i&-i))
        sum+=c[i];
    return sum;
}

int main()
{
    int i,p,d,w,op,q1,q2,ans;
    cin>>n>>k>>A>>B>>q;
    swap(A,B);
    for(i=1;i<=q;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&d,&w);
            if(a[d]<A)
                q1=min(a[d]+w,A)-a[d];
            else q1=0;
            if(a[d]<B)
                q2=min(a[d]+w,B)-a[d];
            else q2=0;
            a[d]+=w;
            //debug(q1);
            //debug(q2);
            upd(c1,d,q1);
            upd(c2,d,q2);
        }
        else
        {
            scanf("%d",&p);
            ans=(get(c1,p-1)-get(c2,p+k-1))+get(c2,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))