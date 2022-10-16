#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,m;
int ans;
signed main(){
	cin>>n>>m;
	for (int i=0;i<m&&i<=n;i++)
		for (int j=0;j<m&&j<=n;j++)
			if ((i*i+j*j)%m==0)ans+=((i>0)+(n-i)/m)*((j>0)+(n-j)/m);
	cout<<ans<<endl;
	return 0;
}