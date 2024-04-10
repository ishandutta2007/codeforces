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
int t,n,k;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		if (2*k-1>n){
			cout<<-1<<endl;
			continue;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j&&(i&1)&&((i+1)/2<=k))putchar('R');
				else putchar('.');
			}
			puts("");
		}
	}
	return 0;
}