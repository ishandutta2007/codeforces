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
int n,m,ans=1;
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n+m;i++)ans=ans*2%mod;
	cout<<ans<<endl;
	return 0;
}