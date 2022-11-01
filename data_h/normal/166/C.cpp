#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 100000;
int A[MAXN], N, x, flag, Ans;
void Init()
{
	flag = 0;
	scanf("%d %d",&N,&x);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&A[i]);
		if (A[i] == x)
			flag = 1;
	}
	if (!flag)
		A[++N] = x, Ans++;
	sort(A + 1, A + N + 1);
}

void Work()
{
	int i, l, r, num, lc, rc;
	for(i = 1;i <= N;i++)
		if (A[i] == x)
			break;
	for(l = i - 1;l >= 1 && A[l] == x;l--);
	for(r = i;r <= N && A[r] == x;r++);
	num = r - l - 1;
	lc = l; rc = N - r + 1;
	int p;
	if (lc < rc)
	{
		lc += (p = min(rc - lc, num));
		num -= p;
	}
	else
	if (lc > rc)
	{
		rc += (p = min(lc - rc, num - 1));
		num -= p;
	}
	printf("%d\n",Ans + abs(rc - lc));
}

int main()
{
	Init();
	Work();
	return 0;
}