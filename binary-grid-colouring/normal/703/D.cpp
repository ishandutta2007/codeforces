#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
const int maxn = 1e6+7;
int a[maxn],sum[maxn],pre[maxn],c[maxn],ans[maxn];
map<int,int>vis;

struct Node
{
	int l,r,id;
}q[maxn];

int lowbit(int x){
	return x & (-x);
}

void update(int i,int num)
{
	while(i<=maxn){
		c[i]^=num;
		i+=lowbit(i);
	}
}

int query(int i)
{
	int ans = 0;
	while(i)
	{
		ans^=c[i];
		i-=lowbit(i);
	}
	return ans;
}

bool cmp(Node a, Node b)
{
	if(a.r==b.r) return a.l<b.l;
		return a.r<b.r;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i =1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]^a[i];
		pre[i] = vis[a[i]];
		vis[a[i]] = i;
	}
	int m;
	scanf("%d",&m);
	for(int i= 1; i <= m; i++){
		scanf("%d%d",&q[i].l,&q[i].r), q[i].id = i;
	}		
		sort(q+1, q+1+m, cmp);
		for(int i = 1, r=1; i<=m; i++ ){
			while(r <= q[i].r){
				if(pre[r])
					update(pre[r],a[r]);
				update(r,a[r]);
				r++;
			}
			ans[q[i].id] = query(q[i].r) ^query(q[i].l - 1) ^ sum[q[i].r] ^ sum[q[i].l-1];
		}
		for(int i = 1; i<=m; i++)
		{
			printf("%d\n",ans[i]);
		}
	
	return 0;
}