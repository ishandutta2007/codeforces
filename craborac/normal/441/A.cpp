#include<cstdio>
int minn[100];
int main()
{
	int n, v;
	scanf("%d %d", &n, &v);
	int coll = 0;
	for(int i = 0; i < n; i++)
	{
		int col = 0;
		scanf("%d", &col);
		minn[i] = (int)1e6;
		for(int j = 0; j < col; j++)
		{
			int a;
			scanf("%d", &a);
			if(a < minn[i])
				minn[i] = a;
		}
		if(v > minn[i])
			coll++;
	}
	printf("%d\n", coll);
	for(int i = 0; i < n; i++)
		if(v > minn[i])
			printf("%d ", i + 1);
	return 0;
}