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
#define INF 100000000
#define fi first
#define se second
#define N 100005
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Peo
{
    int l,r,k,num;
}p[N],q[N];
bool cmp(Peo a,Peo b)
{
    return a.l<b.l;
}
set<pii> s;
int ans[N];
int main()
{
    int n,m,i,j=1,x;
    set<pii>::iterator it;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].num=i;
    sort(q+1,q+1+n,cmp);
    cin>>m;
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].k),p[i].num=i;
    sort(p+1,p+1+m,cmp);
    for(i=1;i<=n;i++)
    {
        for(;j<=m&&p[j].l<=q[i].l;j++)
            s.insert(make_pair(p[j].r,j));
        it=s.lower_bound(make_pair(q[i].r,0));
        if(it==s.end())
        {
            printf("NO\n");
            return 0;
        }
        x=(*it).second;
        ans[q[i].num]=p[x].num;
        p[x].k--;
        if(p[x].k==-1) while(1);
        if(p[x].k==0)
            s.erase(make_pair(p[x].r,x));
    }
    printf("YES\n");
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);