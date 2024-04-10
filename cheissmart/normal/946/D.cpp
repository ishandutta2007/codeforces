#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int dp[548]={};
	while(n--) {
		vector<int> v;
		int a[505];
		memset(a,0x3f,sizeof(a));
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++) if(s[i]-'0') v.push_back(i);
		if (!v.size())
			continue;
		int k2 = min(k, (int)v.size() - 1);
		for(int i=0;i<=k2;i++)
			for(int j=0;j<=i;j++)
				a[i] = min(a[i],v[v.size()-1-(i-j)] - v[j] + 1);
		memset(a+k2+1,0,(k-k2)*sizeof(int));
		//update dp
		for (int i=k;i>=0;--i) {
			int best = 0x3f3f3f3f;
			for(int j=0;j<=i;j++)
				best = min(dp[j]+a[i-j],best);
			dp[i]=best;
		}

	}
	cout << dp[k] << endl;
}