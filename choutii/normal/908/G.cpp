
#include <cstdio>
#include <cstring> 

using namespace std;

const int Max_L(705);
const int MOD(1000000000 + 7);
typedef long long int LL; 

inline void update(int &a, const int &b)
{
	((a += b) >= MOD) ? (a -= MOD) : 0;
}

inline int Mult(const int &a, const int &b)
{
	return static_cast<int>(static_cast<LL>(a) * static_cast<LL>(b) % static_cast<LL>(MOD));
}

int L, power[Max_L], Sum[Max_L];
char S[Max_L];

void init()
{
	scanf("%s", S + 1), L = strlen(S + 1);
	power[0] = Sum[0] = 1;
	for (int i = 1;i <= L;++i)
	{
		power[i] = Mult(power[i - 1], 10);
		update(Sum[i] = Sum[i - 1], power[i]);
	}
}

int Ans, F[Max_L][Max_L][2]; 
void dp(const int &k)
{
	memset(F, 0, sizeof(F));
	F[L + 1][0][1] = 1;
	for (int i = L;i >= 1;--i)
		for (int j = 0;j <= L - i;++j)
			for (int p = 0, q;p <= 1;++p)
				for (int nowd = 0;nowd <= 9;++nowd)
				{
					q = ((nowd + '0' < S[i]) || (nowd + '0' == S[i] && p));
					update(F[i][j + (nowd >= k)][q], F[i + 1][j][p]);
				}
	for (int j = 1;j <= L;++j)
		update(Ans, Mult(F[1][j][1], Sum[j - 1]));
}

int main()
{
	init();
	for (int d = 1;d <= 9;++d)
		dp(d);
	printf("%d", Ans);
	return 0;
}