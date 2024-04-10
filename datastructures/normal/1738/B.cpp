#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int t,n,k,s[100005],a[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=n-k+1;i<=n;i++){
			cin>>s[i];
			if (i>n-k+1)a[i]=s[i]-s[i-1];
		}
		if (k==1)puts("YES");
		else{
			a[n-k+1]=a[n-k+2];
			int fg=1;
			if (a[n-k+1]*(n-k+1)<s[n-k+1])fg=0;
			for (int i=n-k+2;i<=n;i++)
				if (a[i]<a[i-1])fg=0;
			if (fg==1)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}