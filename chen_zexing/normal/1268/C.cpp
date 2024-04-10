#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<iterator>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
#define eps 1e-8
 
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 200100;
const int mod = 1000000007;
int lz[4*maxn], a[maxn], b[maxn], c[maxn];
LL ans[maxn], p[4*maxn];
void creat(int l, int r, int k);
void pushdown(int k, int l, int r);
int getId(int l, int r, int x, int k);
LL query(int l, int r, int al, int ar, int k);
void Update(int l, int r, int al, int ar, int k);

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	creat(1, n, 1);
	//
	for(i=1;i<=n;i++)
	{
		ans[i] = ans[i-1]+query(1,n,b[i], n, 1);
		Update(1, n, b[i], b[i], 1);
		//c[i]c[i]pic[i]k-pi
		c[i] = getId(1, n, i/2+1, 1);
	}
	//
	creat(1, n, 1);
	for(i=1;i<=n;i++)
	{
		Update(1, n, b[i], n, 1);
		LL sum = query(1, n, 1, c[i]-1, 1) + (LL)i*(n-c[i]+1) - query(1, n, c[i], n, 1);
		LL l = (i-1)/2, r=i-1-l;
		sum -= (l+1)*l/2 + (r+1)*r/2;
		ans[i] += sum;
	}
	for(i=1;i<=n;i++)
		printf("%I64d ", ans[i]);
	return 0;
}

void creat(int l, int r, int k)
{
	p[k] = 0;
	lz[k] = 0;
	if(l == r)return;
	int mid = (l+r)/2;
	creat(l, mid, 2*k);
	creat(mid+1, r, 2*k+1);
}

void Update(int l, int r, int al, int ar, int k)
{
	p[k] += (ar-al+1);
	if(l ==al && ar == r){
		lz[k]++;
		return ;
	}
	pushdown(k, l, r);
	int mid = (l+r)/2;
	if(ar <= mid)Update(l, mid, al, ar, 2*k);
	else if(al > mid)Update(mid+1, r, al, ar, 2*k+1);
	else Update(l, mid, al, mid, 2*k),
			Update(mid+1, r, mid+1, ar, 2*k+1);
}

void pushdown(int k, int l, int r)
{
	if(lz[k])
	{
		int mid = (l+r)/2;
		lz[2*k] += lz[k];
		lz[2*k+1] += lz[k];
		p[2*k] += lz[k] *(mid-l+1);
		p[2*k+1] += lz[k] *(r-mid);
		lz[k] = 0;
	}
}

LL query(int l, int r, int al, int ar, int k)
{
	if(al > ar)return 0;
	if(l == al && r == ar)
		return p[k];
	int mid = (l+r)/2;
	pushdown(k, l, r);
	if(ar <= mid)
		return query(l, mid, al, ar, 2*k);
	else if(al > mid)
		return query(mid+1, r, al, ar, 2*k+1);
	else
		return query(l, mid, al, mid, 2*k)+
				query(mid+1, r, mid+1, ar, 2*k+1);
}

int getId(int l, int r, int x, int k)
{
	if(l == r)return l;
	int mid = (l+r)/2;
	pushdown(k, l, r);
	if(x <= p[2*k])return getId(l, mid, x, 2*k);
	else return getId(mid+1, r, x-p[2*k], 2*k+1);
}