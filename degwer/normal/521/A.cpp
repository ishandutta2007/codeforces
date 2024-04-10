#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int cnt[26];
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		char z;
		scanf(" %c", &z);
		cnt[z - 'A']++;
	}
	int maxi = 0;
	for (int i = 0; i < 26; i++)maxi = max(maxi, cnt[i]);
	int c = 0;
	for (int i = 0; i < 26; i++)if (maxi == cnt[i])c++;
	ll r = 1;
	for (int i = 0; i < num; i++)r = (r*c) % mod;
	printf("%I64d\n", r);
}