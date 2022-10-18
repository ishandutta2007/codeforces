#include<stdio.h>

struct SEG
{
	int v, c, a, b;
	char word[10];

	void scan()
	{
		
		scanf("%d%s%d%d",&v,word,&a,&b);
		c= word[0]=='T';
	}
};

SEG seg[120];
int n, hl, hr;
int mark[120];

typedef __int64 LL;
int through(LL x1, LL y1, LL x2, LL y2, LL x3, LL x4, LL yy)
{
	LL temp = (yy - y2)*(x2 - x1) + x2*(y2 - y1);
	return x3*(y2 - y1) <= temp && temp <= x4*(y2-y1);
}

int process()
{
	int ans = 0;

	int i, x1, y1, x2, y2, x3, x4, yy;
	int id, f, j, layer, looking, now;

	for(i = 1; i <= n; i++)
	{
		for(j=0;j<n;j++) mark[j] = 0;

		x1 = 0;
		y1 = hl;

		x2 = 100000;
		
		if(i%2)
			y2 = (i+1)*100 - hr;
		else
			y2 = i*100 + hr;

		f = 1;
		for(layer = 1; layer <= i; layer++)
		{
			if(layer%2)
				looking = 1;
			else
				looking = 0;

			id = -1;
			for(j = 0; j < n; j++)
				if(looking == seg[j].c)
				{
					x3 = seg[j].a;
					x4 = seg[j].b;
					yy = layer*100;

					if(through(x1, y1, x2, y2, x3, x4, yy))
					{
						id = j;
						break;
					}
				}

			if(id==-1 || mark[id])
			{
				f = 0;
				break;
			}

			mark[id] = 1;
		}

		if(!f) continue;
		now = 0;
		for(j = 0; j < n; j++)
			if(mark[j])
				now += seg[j].v;
		if(ans < now) ans = now;
	}

	return ans;
}

int main()
{
	int i, ans1, ans2;

	scanf("%d%d%d", &hl, &hr, &n);
	for(i=0;i<n;i++)
	{
		seg[i].scan();
	}

	ans1 = process();

	hl = 100 - hl;
	hr = 100 - hr;
	for(i = 0; i < n; i++)
		seg[i].c ^= 1;

	ans2 = process();
	
	if(ans1 < ans2) ans1 = ans2;

	printf("%d\n", ans1);

	return 0;
}