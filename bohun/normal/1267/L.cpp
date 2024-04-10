#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
int n, i, j, l, k, s, a, b, x;
char str [N*N];
char out [N][N];

int main ()
	{
	scanf ("%d%d%d", &n, &l, &k);
	scanf ("%s", str);
	s = strlen(str);
	sort(str, str+s);
	j = 0;
	a = 0;
	b = k-1;
	for (x=0; x<l; x++)
		{
//		printf ("x=%d a=%d b=%d\n", x, a, b);
		for (i=a; i<=b; i++)
			out[i][x] = str[j++];
		for (i=b; i>=a; i--)
			if (out[i][x]!=out[b][x])
				break;
		a = i+1;
		}
	
	for (i=0; i<n; i++)
		for (x=0; x<l; x++)
			if (out[i][x] == 0)
				out[i][x] = str[j++];
	
	for (i=0; i<n; i++)
		{
		for (j=0; j<l; j++)
			printf ("%c", out[i][j]);
		printf ("\n");
		}
	
	return 0;
	}