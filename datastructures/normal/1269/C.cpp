#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
char s[2000005];
int n,m,a[200005],b[200005];
inline bool check(){
	for (int i=1;i<=n;i++){
		if (a[i]>b[i])return 0;
		if (b[i]>a[i])return 1;
	}
	return 1;
}
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)a[i]=s[i]-'0';
	for (int i=1;i<=m;i++)b[i]=a[i];
	for (int i=m+1;i<=n;i++)b[i]=b[i-m];
	if (check()){
		cout<<n<<endl;
		for (int i=1;i<=n;i++)printf("%d",b[i]);
		cout<<endl;
		return 0;
	}
	b[m]++;
	for (int i=m;i>=1;i--){
		b[i-1]+=b[i]/10;
		b[i]%=10;
	}
	for (int i=m+1;i<=n;i++)b[i]=b[i-m];
	if (check()){
		cout<<n<<endl;
		for (int i=1;i<=n;i++)printf("%d",b[i]);
		cout<<endl;
		return 0;
	}	
	return 0;
}