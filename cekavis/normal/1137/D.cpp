#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

int x;
char a[233];
int nxt(const char *s){
	puts(s), fflush(stdout), scanf("%d", &x);
	for(int i=0; i<x; ++i) scanf("%s", a);
	return x;
}
int main() {
	while((nxt("next 0 1"), nxt("next 0"))==3);
	while(nxt("next 0 1 2 3 4 5 6 7 8 9")==2);
	return puts("done"), fflush(stdout), 0;
}