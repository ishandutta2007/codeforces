#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.end(),greater<int>());
	int res=0;
	for(int i=0;i<n;i++) if(v[i]>=v[k-1]&&v[i]>0) res++;
	cout << res << endl;
	return 0;
}