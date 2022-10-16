#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int a[N], b[N];
vector<pair<int,int>> v;
int main()
{
	int n, m, k;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		cin >> b[i];
	cin >> k;
	for(int i=0;i<m;i++)
		for(int j=i,s=0;j<m;j++)
			v.push_back({s+=b[j],j-i+1});
	sort(v.begin(), v.end());
	for(int i=1;i<v.size();i++)
		v[i].second = max(v[i].second,v[i-1].second);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i,s=0;j<n;j++) {
			s+=a[j];
			//s * bs <= k
			//bs <= k/s
			int t=upper_bound(v.begin(),v.end(),(pair<int,int>){k/s,1000000000})-v.begin();
			if (t>0)
				ans=max(ans, v[t-1].second * (j-i+1));
		}
	cout << ans << endl;
}