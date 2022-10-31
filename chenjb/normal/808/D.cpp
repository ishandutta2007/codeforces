#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
set<LL> dic;
int n;
LL a[200000];
int main()
{
	cin>>n;
	LL target=0;
	for(int i=1;i<=n;i++){ scanf("%i64d",&a[i]); target+=a[i]; }
	if (target%2)
	{

		cout<<"NO"<<endl;
		return 0;
	}
	target/=2;
	int flag=0;
	LL sum=0;
	dic.clear();
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		dic.insert(a[i]);
		if (sum<target)continue;
		if (sum==target){ flag=1; break; }
		if (dic.find(sum-target)!=dic.end()){flag=1; break; }
	}

	sum=0;
	dic.clear();
	for(int i=n;i>=1;i--)
	{
		sum+=a[i];
		dic.insert(a[i]);
		if (sum<target)continue;
		if (sum==target){ flag=1; break; }
		if (dic.find(sum-target)!=dic.end()){flag=1; break; }
	}

	if (flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}