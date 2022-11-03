#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int module = 1e9+7;

int n,m;
int cnt[2222][2222],cnth[2222][2222];
int sum[2222][2222];

int main()
{
//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	for (int i=2; i<=2000; i++)
	{
		cnt[1][i]=(1LL*i*(i-1)/2)%module;
		sum[1][i]=(sum[1][i-1]+cnt[1][i])%module;
	}
	for (int i=2; i<=2000; i++)
		for (int j=2; j<=2000; j++)
		{
			cnt[i][j]=(cnt[i][j-1]+sum[i-1][j])%module;
			sum[i][j]=(sum[i][j-1]+cnt[i][j])%module;
		}
	for (int i=1; i<=2000; i++)
		for (int j=0; j<=2000; j++)
			cnth[i][j]=(cnth[i-1][j]+cnt[i][j])%module;
	cin >> n >> m; 
	int ans=0;
	for (int i=0; i<n; i++)
		for (int l=2; l<=m; l++)
		{
			int s = 1;
			s = (s+cnth[n-i-1][l])%module;
			int r = (2LL*cnth[i][l-1])%module-cnth[i][l-2];
			while (r < 0) r += module;
			s = (s+r)%module;
			s = (s+(1LL*r*cnth[n-i-1][l])%module)%module;
			ans = (ans + (1LL*(m-l+1)*s)%module)%module;
		}
	cout << ans << endl;
	return 0;
}