#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
char a[100005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("932A.in", "r", stdin); 
#endif
	scanf("%s", a); 
	printf("%s", a);
	std::reverse(a, a + strlen(a)); 
	puts(a); 
	return 0; 
}