#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <random>
#include <ctime>
using namespace std;
mt19937 rnd(time(NULL));
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int t,n,a[105],b[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		int fg=1;
		for (int i=1;i<=n;i++)
			if (a[i]!=b[i]&&a[i]!=b[i]-1)fg=0;
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}