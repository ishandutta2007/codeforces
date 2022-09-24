#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	printf("%d\n", min(min(b, c - 1), a + 1) * 3);
		
	return 0;
}