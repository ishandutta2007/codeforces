#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int num[300005],n,m,i,j,mi;
long long s;
map<int,long long> nums;
int main()
{
	//freopen("in.txt","r",stdin);
	srand(1234567);
	cin>>n;
	for (i=1;i<=n;i++) 
	{
		scanf("%d",&num[i]);
		nums[num[i]]++;
	}
	for (i=1;i<=n;i++) swap(num[i],num[rand()%n+1]);
	sort(num+1,num+n+1);
	if (num[1]==num[2])
	{
		if (num[2]==num[3])
		{
			s=nums[num[1]];
			cout<<s*(s-1)*(s-2)/6;
			return 0;
		}
		else
		{
			s=nums[num[1]];
			cout<<s*(s-1)*(nums[num[3]])/2;
			return 0;
		}
	}
	else if (num[2]==num[3])
	{
		s=nums[num[2]];
		cout<<s*(s-1)*(nums[num[1]])/2;
		return 0;
	}
	else
	{
		cout<<(nums[num[1]])*(nums[num[2]])*(nums[num[3]]);
		return 0;
	}
	return 0;
}