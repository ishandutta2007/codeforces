#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int maxi[200000];
vector<int>que[200001];
int st[200001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 1; i < num; i++)que[gcd(i, num)].push_back(i);
	ll ans = 0;
	for (int i = 1; i < num; i++)
	{
		if (num%i == 0)
		{
			int now = 0;
			vector<int>dat;
			dat.resize(num);
			fill(maxi, maxi + num, 0);
			int c = 0;
			for (int j = 0; j < num / i; j++)
			{
				for (int k = 0; k < i; k++)
				{
					maxi[k] = max(maxi[k], vec[c]);
					c++;
				}
			}
			c = 0;
			for (int j = 0; j < num / i; j++)
			{
				for (int k = 0; k < i; k++)
				{
					if (maxi[k] == vec[c])now++;
					else now = 0;
					dat[c] = now;
					c++;
				}
			}
			c = 0;
			for (int j = 0; j < num / i; j++)
			{
				for (int k = 0; k < i; k++)
				{
					if (maxi[k] == vec[c])now++;
					else now = 0;
					if (now > num)now = num;
					dat[c] = now;
					c++;
				}
			}
			fill(st, st + num + 1, 0);
			for (int j = 0; j < num; j++)st[dat[j]]++;
			for (int j = num - 1; j >= 0; j--)st[j] +=st[j + 1];
			for (int j = 0; j < que[i].size(); j++)
			{
				ans += st[que[i][j]];
				//if(num-low!=0)printf("%d %d\n", que[i][j], num - low);
			}
		}
	}
	printf("%I64d\n", ans);
}