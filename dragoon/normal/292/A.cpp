#include<stdio.h>

int n, t[1003], c[1003];
int now, last, amount, maxsz, total;

#define MAX(A, B) ((A)>(B)?(A):(B))

int main()
{
	int i, head, remaining;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &t[i], &c[i]);

	head = 1;
	
	last = t[0];
	maxsz = c[0];
	now = t[0];
	total = c[0];
	
	for(i = 0; i < n; i++)
	{
		if(now < t[i])
		{
			total = c[i];
			now = t[i];
			last = t[i];
			maxsz = MAX(maxsz, c[i]);
			head = i+1;
		}

		amount = c[i];
		while(amount)
		{
			if(head == n)
			{
				now = last = now + amount;
				maxsz = MAX(maxsz, total);
				total -= amount;
				amount = 0;
			}
			else
			{
				remaining = t[head] - now;
				if( remaining >= amount )
				{
					last = now + amount;
					total -= amount;
					now = last;
					amount = 0;
				}
				else
				{
					amount -= remaining;
					last = now + remaining;
					now = last;
					total -= remaining;

					total += c[head];
					maxsz = MAX(maxsz, total);
					head++;
				}
			}
		}
		
	}

	printf("%d %d\n", last, maxsz);

	return 0;
}