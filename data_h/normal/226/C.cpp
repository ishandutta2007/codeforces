#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

long long L, R, M, K;

long long ans = 0;

const int size = 2;

struct Matrix
{
	long long dat[size][size];
	void clear()
	{
		memset(dat, 0, sizeof(dat));
	}
	friend Matrix operator *(Matrix a, Matrix b)
	{
		Matrix c;
		c.clear();
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				for(int k = 0; k < size; k++)
					c.dat[i][j] = (c.dat[i][j] + a.dat[i][k] * b.dat[k][j] % M) % M;
		return c;
	}
};

Matrix A, B, C;

long long F(long long idx)
{
	if (idx < 0)
		return 1;
	A.clear();
	B.clear();
	A.dat[0][0] = 1;
	A.dat[0][1] = 1;
	B.dat[0][1] = 1;
	B.dat[1][0] = 1; B.dat[1][1] = 1; 
	while(idx)
	{
		if (idx & 1)
			A = A * B;
		idx >>= 1;
		B = B * B;
	}
	return A.dat[0][1];
}

int main()
{
	scanf("%I64d %I64d %I64d %I64d", &M, &L, &R, &K);
	L--;
	for(long long i = 1; i <= R; i++)
	{
		long long step = R / i;
		step = R / step;
		i = step;
		if (L != 0 && i <= L)
		{
			step = L / i;
			step = L / step;
			i = min(step, i);
		}
		if (R / i - L / i >= K)
			ans = i;
	}
	printf("%I64d\n", F(ans - 2) % M);
	return 0;
}