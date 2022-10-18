#pragma warning(disable:4786)
#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;


#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
typedef __int64 LL;

struct Student
{
	int ability, pass, id;
};

struct Task
{
	int complexity, id;
};

Student student[100005];
Task task[100005];
int ans[100005], m, n;

bool operator<(Task A, Task B)
{
	return A.complexity < B.complexity;
}

bool cmp(Student A, Student B)
{
	return A.ability < B.ability;
}

bool operator<(Student A, Student B)
{
	return A.pass > B.pass;
}

int S;
int f(int lim)
{
	priority_queue<Student> PQ;
	Student u;

	int pos, end, now, i;

	LL curS = 0;
	pos = m - 1;
	end = n - 1;
	while(pos >= 0)
	{
		now = task[pos].complexity;
		while(end >= 0 && student[end].ability >= now) 
		{
			PQ.push(student[end]);
			end--;
		}

		if(PQ.empty()) return 0;

		u = PQ.top();
		PQ.pop();

		curS += u.pass;
		for(i = pos; i >= pos - lim + 1 && i >= 0; i--) ans[task[i].id] = u.id;
		pos = pos - lim;
	}

	return curS <= S;
}

int main()
{
	int i;
	int lo, hi, mid;

	scanf("%d %d %d", &n, &m, &S);
	FORN(i, m) 
	{
		scanf("%d", &task[i].complexity);
		task[i].id = i;
	}

	sort(task, task + m);

	FORN(i, n) {scanf("%d", &student[i].ability); student[i].id = i + 1;}
	FORN(i, n) scanf("%d", &student[i].pass);

	sort(student, student + n, cmp);

	if(student[n - 1].ability < task[m - 1].complexity)
	{
		printf("NO\n");
		return 0;
	}

	lo = 1;
	hi = m;
	while( lo < hi )
	{
		mid = (lo + hi)/ 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}
	if(!f(m))
	{
		printf("NO\n");
		return 0;
	}
	f(lo);


	printf("YES\n");
	FORN(i, m) 
	{
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}