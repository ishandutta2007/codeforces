#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
using namespace std; 
typedef long long ll; 
set<char> se = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'}; 
char str[55]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908A.in", "r", stdin); 
#endif
	scanf("%s", str); 
	int ans = 0; 
	for (int i = 0; str[i]; i++)
		ans += se.count(str[i]); 
	printf("%d\n", ans);
	return 0; 
}