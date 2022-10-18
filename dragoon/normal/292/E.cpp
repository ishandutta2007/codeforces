#include<stdio.h>

struct PII
{
	int Apos, Bpos, len;

	PII(int a, int b, int c)
	{
		Apos = a;
		Bpos = b;
		len = c;
	}

	PII()
	{}
};

PII delay[400005];
int A[100005], B[100005];

void build(int at, int l, int r)
{
	if( l == r )
	{
		delay[at] = PII(0, 0, 0);
		return;
	}

	int mid = (l + r)/2;
	
	build(at*2, l, mid);
	build(at*2 + 1, mid + 1, r);

	delay[at] = PII(0, 0, 0);
}

void Push(int at, int l, int r)
{
	delay[at*2] = delay[at];
	delay[at*2+1] = delay[at];
	delay[at] = PII(0, 0, 0);
}

void modify(int at, int l, int r, int x, int y, int k)
{
	if(r < y) return;
	if(y+k-1 < l) return;

	if(y<=l && r<=y+k-1)
	{
		delay[at] = PII(x, y, k);
		return;
	}

	if(delay[at].Apos)
		Push(at, l, r);

	int mid = (l + r)/2;
	modify(at*2, l, mid, x, y, k);
	modify(at*2 + 1, mid + 1, r, x, y, k);
}

int query(int at, int l, int r, int q)
{
	if(l==r)
	{
		if(delay[at].Apos == 0) return B[q];
		else return A[delay[at].Apos + q - delay[at].Bpos];
	}

	if( delay[at].Apos )
		Push(at, l, r);

	int mid = (l + r)/2;

	if(q <= mid) return query(at*2, l, mid, q);
	else return query(at*2+1, mid+1, r, q);
}

int main()
{
	int n, m, i, x, y, k, t, ans;

	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++)
		scanf("%d", &A[i]);

	for(i = 1; i <= n; i++)
		scanf("%d", &B[i]);

	build(1, 1, n);

	while( m-- )
	{
		scanf("%d", &t);

		if( t == 1 ) //copy
		{
			scanf("%d %d %d", &x, &y, &k);
			modify(1, 1, n, x, y, k);
		}
		else //query
		{
			scanf("%d", &x);
			ans = query(1, 1, n, x);
			printf("%d\n", ans);
		}
	}


	return 0;
}