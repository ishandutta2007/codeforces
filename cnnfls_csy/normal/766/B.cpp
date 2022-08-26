#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int a[100005],n,i,j;
map<int,int> b;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	for (i=1;i<=n-2;i++)
	if (a[i]+a[i+1]>a[i+2]) {cout<<"YES";return 0;}
	cout<<"NO";
	return 0;
}