#include <bits/stdc++.h>
using namespace std;
bool ok(int res, int d) {
	long long sum = res * 1LL * (res + 1) / 2;
	if(sum < d) return false;
	return sum % 2 == d % 2;
}
int main() 
{
	int t,a,b;
	cin >> t;
	while(t--)
	{
		cin>>a>>b;
		int d=abs(a-b),res=1;
		if(d==0) 
		{
			cout << "0\n";
			continue;
		}
		while(!ok(res, d)) ++res;
		cout<<res<<endl;
	}
	return 0;
}