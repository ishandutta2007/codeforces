#include<stdio.h>
#include<algorithm>
using namespace std;

struct Task
{
	int L, p;
	Task(int a, int b) { L = a, p = b; }
	Task(){}
};

Task t[50004];

bool operator<(Task A, Task B)
{
	int left = A.L*A.p*(100-B.p);
	int right = B.L*B.p*(100-A.p);

	return left > right;
}

int main()
{
	double nq, ans;
	int i, n;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d%d", &t[i].L, &t[i].p);

	sort(t, t+n);

//	for(i = 0; i < n; i++)
//		printf(">>>%d %d\n", t[i].L, t[i].p);

	ans = 0;
	nq = 0;
	for(i = 0; i < n; i++)
	{
		nq += 1. - 1.*t[i].p/100;
		ans += t[i].L;
	}

	for(i = 0; i < n; i++)
	{
		nq -= 1 - 1.*t[i].p/100;
		ans += 1.*t[i].p/100*t[i].L*nq;
	}

	printf("%.10f\n", ans);

	return 0;
}