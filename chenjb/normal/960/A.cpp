#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
char s[11000];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	int a=0,b=0,c=0;
	int i=1;
	for(;i<=len;i++)
		if (s[i]=='a')a++; else break;
	for(;i<=len;i++)
		if (s[i]=='b')b++; else break;
	for(;i<=len;i++)
		if (s[i]=='c')c++; else break;
	if (a+b+c!=len){ puts("NO"); return 0; }
	if (a==0||b==0){ puts("NO"); return 0; }
	if (c==a || c==b){ puts("YES"); return 0; }
	puts("NO");
}