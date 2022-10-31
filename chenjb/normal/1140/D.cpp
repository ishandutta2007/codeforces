#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[310000];
priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
	long long ans=0;
	int n;
	cin>>n;
	for(int i=2;i<n;i++)ans=ans+1ll*i*(i+1);
	cout<<ans<<endl;
	return 0;
}