#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN],b[MAXN];
set<P> s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    for(int i=1;i<=n;i++) scanf("%d%d",&b[i].F,&b[i].S);
    for(int i=1;i<=n;i++) s.insert(b[i]);
    for(int i=1;i<=n;i++)
    {
        bool f=true;
        P now=P(a[1].F+b[i].F,a[1].S+b[i].S);
        for(int j=2;j<=n;j++)
            if(!s.count(P(now.F-a[j].F,now.S-a[j].S))) f=false;
        if(f)
        {
            printf("%d %d\n",now.F,now.S);
            return 0;
        }
    }
    return 0;
}