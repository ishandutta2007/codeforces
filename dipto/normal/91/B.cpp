#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)
#define pb push_back
#define pob() pop_back()
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define mp make_pair
#define fi first
#define se second
#define LD long double
#define SZ 100000
/**************************************************************************************/
vector< pair<int,int> > list;
int ans[SZ],tree[10*SZ];

int qry(int l,int x,int y,int r,int n)
{
if(l==x && r==y) return tree[n];
int m=(l+r)/2;
if(y<=m) return qry(l,x,y,m,2*n);
else if(x>m) return qry(m+1,x,y,r,2*n+1);
else return max( qry(l,x,m,m,2*n), qry(m+1,m+1,y,r,2*n+1));
}

void update(int l,int r,int n,int v)
{
if(l==r) {tree[n]=v;return;}

int m=(l+r)/2;

if(v<=m) update(l,m,2*n,v);
else update(m+1,r,2*n+1,v);

tree[n]=max(tree[2*n],tree[2*n+1]);

}

int main() {
    int N;
    si(N);
    FOR(i,0,N-1)
    {int a;si(a);
    list.pb(mp(a,i));}
    
    sort(list.b(),list.e());
    
    ans[list[0].se]=0;
    update(0,N-1,1,list[0].se);
    FOR(i,1,N-1)
        {
        int ind=list[i].se;
        ans[ind]=qry(0,ind,N-1,N-1,1);
        update(0,N-1,1,ind);
        }
    FOR(i,0,N-1) printf("%d ",ans[i]!=0?(ans[i]-i-1):-1);
return 0;
}