#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;
char s[110000];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)putchar(s[i]);
	for(int i=n;i>=1;i--)putchar(s[i]);
	puts("");
	return 0;
}