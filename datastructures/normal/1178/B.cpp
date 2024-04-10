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
#define int long long
using namespace std;
char s[1000005];
int n,f[1000005],g[1000005],ans;
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=2;i<=n;i++)f[i]=f[i-1]+(s[i]=='v'&&s[i-1]=='v');
	for (int i=n-1;i>=1;i--)g[i]=g[i+1]+(s[i]=='v'&&s[i+1]=='v');
	for (int i=1;i<=n;i++)
		if (s[i]=='o')ans+=f[i]*g[i];
	cout<<ans<<endl;
	return 0;
}