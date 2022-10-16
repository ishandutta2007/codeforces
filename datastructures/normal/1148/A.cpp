#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int a,b,c;
signed main(){
	cin>>a>>b>>c;
	int ans=2*min(a,b);
	if (a!=b)ans++;
	ans+=2*c;
	cout<<ans<<endl;
	return 0;
}