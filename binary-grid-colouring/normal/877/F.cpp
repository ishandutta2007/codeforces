#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#pragma G++ optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
const int maxn = 123456;
int a[maxn],type[maxn];
int n,k;
ll s[maxn],t[maxn];
ll ut[maxn],dt[maxn];
int num;
int sz;
int hs[maxn];

int has(ll x)
{
    return lower_bound(t,t + num, x) - t;
}

struct Query
{
    int l,r,id;
    bool operator <(const Query& qq) const
    {
        if(l/sz != qq.l/sz) return l/sz < qq.l/sz;
        else return r<qq.r;
    }
}query[maxn];

int L,R,q;
int cnt[maxn];
ll ANS;
ll ans[maxn];

int Find(ll x)
{
    int lx=has(x);
    if(lx>=num||t[lx]!=x) return -1;
    else return lx;
}
void add(int i,int op)
{
    if(op)
    {
        if(dt[i]>=0) ANS += cnt[dt[i]];
        cnt[hs[i]]++;
    }
    else
    {
        if(ut[i-1]>=0) ANS += cnt[ut[i-1]];
        cnt[hs[i-1]]++;
    }
}
void del(int i,int op)
{
    if(op)
    {
        --cnt[hs[i]];
        if(dt[i]>=0) ANS -= cnt[dt[i]];
    }
    else
    {
        --cnt[hs[i-1]];
        if(ut[i-1]>=0) ANS -= cnt[ut[i-1]];
    }
}
int main()
{
	n=read(),k=read();
//	sz = (int)sqrt(n*1.0);
	sz = 375;
	for(int i=1;i<=n;i++)
	{
		type[i] = read();// 
	}
	for(int i=1;i<=n;i++)
	{
		a[i] = read();
		if(type[i]==1) s[i] = s[i-1] + a[i];//math problem 
		else s[i] = s[i-1] - a[i];//economics problem 
	}
//	num = 0;
	for(int i=0;i<=n;i++) t[num++] = s[i];
	
	sort(t,t + num);
	num = unique(t,t + num) - t;
	
	for(int i=0;i<=n;i++)
	{
		hs[i] = has(s[i]);
		ut[i] = Find(s[i]+k);
		dt[i] = Find(s[i]-k);
	}
	q=read();
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&query[i].l,&query[i].r);
        query[i].id=i;
	}
	
	sort(query,query + q);	
    L = 1;
	R = 0;
	ANS = 0;
    cnt[hs[0]]++;
    for(int i=0;i<q;i++)
    {
        while(R<query[i].r)add(++R,1);
        while(R>query[i].r)del(R--,1);
        while(L<query[i].l)del(L++,0);
        while(L>query[i].l)add(--L,0);
        ans[query[i].id] = ANS;
    }
    for(int i=0;i<q;i++)
	{
		printf("%I64d\n",ans[i]);
	} 
	return 0;
}