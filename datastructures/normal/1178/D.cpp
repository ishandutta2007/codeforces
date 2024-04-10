#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <random>
#define mod 998244353
#define int long long
using namespace std;
int n,m;
bool isp(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
signed main(){
	cin>>n;
	m=n;
	while(!isp(m))m++;
	cout<<m<<endl;
	for (int i=1;i<n;i++)cout<<i<<' '<<i+1<<endl;
	cout<<n<<' '<<1<<endl;
	int l=1,r=n-1;
	for (int i=n+1;i<=m;i++)cout<<l<<' '<<r<<endl,l++,r--;
	return 0;
}