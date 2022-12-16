#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int k,a,b, big, small;
	scanf("%d %d %d", &k, &a, &b);

	if(a < k & b < k)
		printf("-1\n");
	else {
		if(a < k && (b%k != 0 && k != 1))
			printf("-1\n");
		else if(b < k && (a%k != 0 && k != 1))
			printf("-1\n");
		else {
	
			big = a;
			small = b;
			if(b > a)
			{
				small = a;
				big = b;
			}

			int paircount = (small)/k;
			int counter = 2*paircount;
			
			small -= paircount*(k);
			big -= paircount*(k);
			
			int mamt = big/k;
			
			counter += mamt;
			printf("%d\n", counter);
/*
			int mincount = (big)/11;
			int minn = 10*mincount;
			if(big%11 != 0)
			{
				minn+=11;
				mincount++;
			}
			if(minn > b)
			{
				
			}
*/
			
		}
	}

	return 0;
}