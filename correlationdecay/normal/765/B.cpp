#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#define maxn 100009
using namespace std;
char s[maxn];
int cur = 0;
int main(){
	scanf("%s", s);
	for(int i = 0; s[i]; i++){
		int x = s[i] - 'a';
		if(x < cur)
			continue;
		else if(x == cur)
			cur++;
		else{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}