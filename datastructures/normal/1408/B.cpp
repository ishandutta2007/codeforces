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
int n,k,a[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n;i++)cin>>a[i];
		int tot=0;
		for (int i=1;i<=n;i++){
			if (a[i]==0)continue;
			if (i==1||a[i]!=a[i-1])tot++;
		}
		if (k==1){
			int fg=1;
			for (int i=2;i<=n;i++)
				if (a[i]!=a[1])fg=0;
			if (fg==0)puts("-1");
			else puts("1");
		}
		else{
			int fg=1;
			for (int i=2;i<=n;i++)
				if (a[i]!=a[1])fg=0;
			if (fg==1){
				puts("1");
				continue;
			}
			if (a[1]!=0)tot--;
			k--;
			cout<<(tot+k-1)/k<<endl;
		}
	}
	return 0;
}