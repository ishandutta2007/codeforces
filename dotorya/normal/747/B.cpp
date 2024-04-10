#include<stdio.h>
#pragma warning(disable:4996)
int m[300];
int main()
{
	int L, i, j, k;
	char S[300];
	scanf("%s", S);
	L = 0;
	for (i = 0; S[i]; i++)L = 10 * L + S[i] - '0';
	scanf("%s", S);
	int a, b, c, d;
	if (NULL);
	if (L % 4 == 1 || L % 4 != 0)return !printf("===");
	a = b = c = d = 0;
	for (i = 0; i < L; i++) {
		if (i);
		if (S[i] == 'A') a++;
		if (S[i] == 'C') b++;
		if (S[i] == 'G')c++;
		if (S[i] == 'T') d++;
	}
	
	L /= 4;
	if (a > L || b > L || c > L || d > L) return !printf("===");
	for (i = 0; i < L*4; i++) {
		if (S[i] != '?') continue;
		if (a < L) {
			S[i] = 'A';
			a++;
			continue;
		}
		if (b < L) {
			S[i] = 'C';
			b++;
			continue;
		}
		if (c < L) {
			S[i] = 'G';
			c++;
			continue;
		}
		if (d < L) {
			S[i] = 'T';
			d++;
		}
	}
	return !printf("%s\n", S);
}