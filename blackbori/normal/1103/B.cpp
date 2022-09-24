#include <bits/stdc++.h>

using namespace std;

char str[55];

bool ask(int a, int b)
{
	printf("? %d %d\n", a, b);
	fflush(stdout);
	scanf("%s", str);
	
	if(str[0] == 'x') return 0;
	else return 1;
}

int main()
{
	for(; ; ){
		int i, s, e, mid;
		
		scanf("%s", str);
		if(str[0] == 'm' || str[0] == 'e') break;
		
		for(i=1; ; i++){
			if(!ask(1 << i - 1, 1 << i)) break;
		}
		
		if(i == 1){
			if(!ask(2, 1)) printf("! 1\n");
			else printf("! 2\n");
			fflush(stdout);
			continue;
		}
		
		s = 1 << i - 1; e = 1 << i;
		for(; ; ){
			if(s + 1 == e) break;
			mid = s + e >> 1;
			if(!ask(s, mid)) e = mid;
			else s = mid;
		}
		
		printf("! %d\n", e);
		fflush(stdout);
	}
	
	return 0;
}