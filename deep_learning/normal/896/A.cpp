#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
string str = "What are you doing at the end of the world? Are you busy? Will you save us?"; 
string a = "What are you doing while sending \"", b = "\"? Are you busy? Will you send \"", c = "\"?";
ll len[100005]; 
char calc(int n, ll k)
{
	if (k >= len[n])
		return '.'; 
	if (!n)
		return str[k]; 
	if (k < a.size())
		return a[k]; 
	k -= a.size(); 
	if (k < len[n - 1])
		return calc(n - 1, k); 
	k -= len[n - 1]; 
	if (k < b.size())
		return b[k]; 
	k -= b.size(); 
	if (k < len[n - 1])
		return calc(n - 1, k); 
	k -= len[n - 1]; 
	if (k < c.size())
		return c[k]; 
	return '.'; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("896A.in", "r", stdin); 
#endif
	int t; 
	scanf("%d", &t); 
	len[0] = str.size(); 
	for (int i = 1; i < 100005; i++)
		len[i] = min(len[i - 1] * 2 + (ll)(a.size() + b.size() + c.size()), 2000000000000000000ll); 
	while (t--)
	{
		int n; 
		ll k;
		scanf("%d%lld", &n, &k); 
		printf("%c", calc(n, k - 1));
	}
	printf("\n");
	return 0; 
}