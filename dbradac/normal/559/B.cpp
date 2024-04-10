#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 200100;

char s1[MAX], s2[MAX];

int Jednaki(int l1, int r1, int l2, int r2)
{
	for (int i=l1; i<=r1; i++)
		if (s1[i] != s2[i-l1+l2])
			return 0;
	return 1;
}

int Eq(int lo1, int hi1, int lo2, int hi2)
{
	if ((hi1 - lo1 + 1) % 2)
		return Jednaki(lo1, hi1, lo2, hi2);

	int mid1 = (lo1 + hi1) / 2;
	int mid2 = (lo2 + hi2) / 2;
	return (Eq(lo1, mid1, lo2, mid2) && Eq(mid1+1, hi1, mid2+1, hi2)) ||
					(Eq(lo1, mid1, mid2+1, hi2) && Eq(mid1+1, hi1, lo2, mid2));
}

int main()
{
	scanf("%s%s", s1, s2);

	int len = (int) strlen(s1);

	printf("%s\n", Eq(0, len-1, 0, len-1) ? "YES" : "NO");

	return 0;
}