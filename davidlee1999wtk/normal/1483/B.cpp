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
int a[N];
int nxt[N], pre[N], L[N], R[N], ans[N];
int main()
{
    int T, n, i, j, k, cnt, last, idle;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cnt=0;
        //link=n;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            nxt[i]= i==n? 1: i+1;
            pre[i]=i==1? n: i-1;
            L[i]=R[i]=i;
        }
        i=1;
        last = 0;
        idle=0;
        while(idle<=n && cnt<n)
        {
            //debug(i);
            idle++;
            if(last == 0)
            {
                i=R[i];
                last=a[i];
                i=nxt[i];
            }
            else
            {
                if(__gcd(last, a[i])==1)
                {
                    ans[++cnt]=i;
                    idle=0;
                    last=0;
                    j=nxt[i];
                    
                    pre[nxt[i]]=pre[i];
                    nxt[pre[i]]=nxt[i];
                    if(R[i]!=i)
                        R[j]=R[i], L[R[i]]=j, L[j]=j;
                    i=R[j];
                }
                else // merge
                {
                    k=pre[i];
                    R[L[k]]=R[i];
                    L[R[i]]=L[k];
                    i=R[i];
                    last=a[i];
                    i=nxt[i];
                }
            }
        }
        cout<<cnt<<" ";
        for(i=1;i<=cnt;i++)
            printf("%d ",ans[i]);
        cout<<endl;
    }
    return 0;
}
// davidlee1999WTK 2021/
// srO myk Orz
//ios::sync_with_stdio(false);