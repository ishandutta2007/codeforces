#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> PII;

struct Task
{
	int start, end, id;
};

bool cmp(Task a, Task b)
{
	return a.start < b.start;
}

bool operator<(Task a, Task b)
{
	return a.end > b.end;
}

Task task[103];
int ans[103];
priority_queue<Task> Q;

int main()
{
	int n, i, j, now;
	Task X;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&task[i].start,&task[i].end);
		task[i].id = i;
	}

	sort(task,task+n, cmp);

	for(i=0;i<n;)
	{
		for(j=i;j<n;j++)
			if(task[i].start != task[j].start) break;
			else
			{
				Q.push( task[j] );
			}

		now = task[i].start;
		while(!Q.empty() && (j==n || now < task[j].start))
		{
			X = Q.top();
			Q.pop();

			ans[ X.id ] = now;
			now++;
		}

		i = j;
	}

	for(i=0;i<n;i++)
	{
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}