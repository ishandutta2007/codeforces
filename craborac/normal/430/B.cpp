#include<cstdio>
int mas[100];
int col[100];
int main()
{
	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	scanf("%d", &mas[0]);
	col[0] = 1;
	int coll = 1;
	int anss = 0;
	for(int i = 1; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a == mas[coll - 1])
			col[coll - 1]++;
		else
		{
			while(col[coll - 1] >= 3)
			{
				anss += col[coll - 1];
				coll--;
			}
			if(a == mas[coll - 1])
				col[coll - 1]++;
			else
			{
				mas[coll] = a;
				col[coll] = 1;
				coll++;
			}
		}
	}	
	if(col[coll - 1] >= 3)
	{
		anss += col[coll - 1];
		coll--;
	}
	int answer = 0;
	for(int i = 0; i < coll; i++)
	{
		if((mas[i] == x) && (col[i] >= 2))
		{
			int l = i - 1;
			int r = i + 1;
			int ans = anss + col[i];
			while((l >= 0) || (r < coll))
			{
				while((l >= 0) && (col[l] >= 3))
				{
					ans += col[l];
					l--;
				}
				while((r < coll) && (col[r] >= 3))
				{
					ans += col[r];
					r++;
				}
				if((l >= 0) && (r < coll) && (mas[l] == mas[r]) && (col[l] + col[r] >= 3))
				{
					ans += col[l];
					ans += col[r];
					l--;
					r++;
				}
				else if((l >= 0) && (col[l] >= 3))
				{
					ans += col[l];
					l--;
				}
				else if((r < coll) && (col[r] >= 3))
				{
					ans += col[r];
					r++;
				}
				else
					break;
			}
			if(ans > answer)
				answer = ans;
		}
	}
	printf("%d", answer);
	return 0;
}