#include <bits/stdc++.h>

using namespace std;

char str[1010101];
deque <int> Q;
int n;

int main()
{
	int i;
	
	scanf("%s", str);
	
	n = strlen(str);
	
	for(i=n; i>=1; i--){
		if(str[i - 1] == 'r') Q.push_front(i);
		else Q.push_back(i);
	}
	
	for(int t: Q) printf("%d\n", t);
	
	return 0;
}