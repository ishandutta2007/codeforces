#include <bits/stdc++.h>

using namespace std;

char S[111];
int D[11];
int n;

int main()
{
	int i, s, f;
	
	scanf("%d", &n);
	
	for(; n --; ){
		scanf("%s", S);
		for(i = 0; i < 10; i ++){
			D[i] = 0;
		}
		s = 0;
		for(i = 0; S[i]; i ++){
			D[S[i] - '0'] ++;
			s += (S[i] - '0');
		}
		
		f = 0;
		if(D[0] == 0) f = 1;
		if(s % 3 != 0) f = 1;
		if((D[0] - 1 + D[2] + D[4] + D[6] + D[8]) == 0) f = 1;
		
		printf("%s\n", f? "cyan" : "red");
	}
	
	return 0;
}