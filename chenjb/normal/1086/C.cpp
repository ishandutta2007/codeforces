#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back

int n,k;
int v[30], xmap[30], save[30], mapx[30];
int a[1100000],b[1100000],s[1100000];

bool add(int d, int c) 
{
	if (xmap[s[d]] == c) return 1;
	if (!xmap[s[d]] && !v[c]) 
	{
		xmap[s[d]] = c;
		v[c] = 1;
		return 1;
	}
	return 0;
}

void print() 
{
	for (int i=1;i<=k;i++) if (!xmap[i]) 
	{
		for (int j=1;j<=k;j++) if (!v[j]) 
		{
			xmap[i] = j;
			v[j] = 1;
			break;
		}
	}

	puts("YES");
	for (int i=1;i<=k;i++) putchar(xmap[i] + 'a' - 1);
	puts("");
	return ;
}

char ss[1100000];
void getstr(int* a)
{
	scanf("%s",ss+1);
	n=strlen(ss+1);
	rep(i,n)a[i]=ss[i]-'a'+1;
}
void init()
{
	scanf("%d",&k);
	getstr(s);
	getstr(a);
	getstr(b);
	memset(xmap, 0, sizeof(xmap));
	memset(v, 0, sizeof(v));
	memset(save, 0, sizeof(save));
	memset(mapx, 0, sizeof(mapx));
}
bool fucka(int t)
{
	if (!add(t, a[t]))return 0; 
	bool flag = 1;
	for (int i=t+1;i<=n;i++) 
	{
		for (int p=a[i]+1;p<=k;p++) 
		if (add(i,p)) 
		{
			print();
			return 1;
		}
		if (!add(i,a[i])) 
		{
			flag = 0;
			break;
		}
	}
	if (flag) 
	{
		print();
		return 1;
	}
	return 0;
}
bool fuckb(int t)
{
	if (!add(t, b[t]))return 0;
	bool flag = 1;
	for (int i=t+1;i<=n;i++) 
	{
		for (int p=1;p<=b[i]-1;p++) 
		if (add(i,p)) 
		{
			print();
			return 1;
		}

		if (!add(i, b[i])) 
		{
			flag = 0;
			break;
		}
	}
	if (flag) 
	{
		print();
		return 1 ;
	}
	return 0;
}
bool work() 
{	
	int t=0;
	rep(i,n)
	{
		if (a[i]!=b[i]){ t=i; break;}
		else if (!add(i,a[i]))return 0;

	}
	if (t==0){ print(); return 1; }
	for (int i=a[t]+1;i<=b[t]-1;i++)
		if (add(t,i)) 
		{
			print();
			return 1;
		}

	for (int i=1;i<=k;i++) mapx[i] = xmap[i], save[i] = v[i];
		
	if (fucka(t))return 1;
	
	for (int i=1;i<=k;i++) xmap[i] = mapx[i], v[i] = save[i];

	if (fuckb(t))return 1;
	
	return 0;
}

int main() 
{
	int T;
	cin>>T;
	while (T--)
	{
		init();
		if (!work())puts("NO");
	}
	return 0;
}