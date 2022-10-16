#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int tac,n,m;
PII a[110];
int main()
{
	scanf("%d",&tac);
	while (tac--)
	{
		scanf("%d%d",&n,&m);
		int m1=0,m2=0;
		for (int i=0;i<m;i++) scanf("%d%d",&a[i].Fst,&a[i].Snd),m1=max(m1,a[i].Fst),m2=max(m2,a[i].Snd);
		if (m1+m2>n)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		for (int i=0;i<m1;i++) printf("R");
		for (int i=0;i<m2;i++) printf("W");
		for (int i=0;i<n-m1-m2;i++) printf("R");
		puts("");
	}
	return 0;
}