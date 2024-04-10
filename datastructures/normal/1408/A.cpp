#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
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
int n,a[105],b[105],c[105],ans[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)cin>>b[i];
		for (int i=1;i<=n;i++)cin>>c[i];
		ans[1]=a[1];
		for (int i=2;i<n;i++){
			if (a[i]!=ans[i-1])ans[i]=a[i];
			if (b[i]!=ans[i-1])ans[i]=b[i];
			if (c[i]!=ans[i-1])ans[i]=c[i];
		}
		if (a[n]!=ans[n-1]&&a[n]!=ans[1])ans[n]=a[n];
		else if (b[n]!=ans[n-1]&&b[n]!=ans[1])ans[n]=b[n];
		else ans[n]=c[n];
		for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}