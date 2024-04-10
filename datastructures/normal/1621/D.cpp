#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define int long long
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t;
int n,a[1005][1005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=2*n;i++)
			for (int j=1;j<=2*n;j++)
				a[i][j]=read();
		int ans;
		ans=min(min(a[1][n+1],a[1][2*n]),min(a[n][n+1],a[n][2*n]));
		ans=min(ans,min(min(a[n+1][1],a[2*n][1]),min(a[n+1][n],a[2*n][n])));
		for (int i=n+1;i<=2*n;i++)
			for (int j=n+1;j<=2*n;j++)
				ans+=a[i][j];
		cout<<ans<<endl;
	}
	return 0;
}