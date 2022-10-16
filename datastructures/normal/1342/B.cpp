#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int T;
char s[100005],t[100005];
signed main(){
	cin>>T;
	while(T--){
		scanf("%s",t+1);
		int n=strlen(t+1);
		int fg=1,len;
		for (int i=1;i<=n;i++)
			if (t[i]!=t[1])fg=0;
		if (fg==1){
			for (int i=1;i<=n;i++)s[i]=t[1];
			len=n;
		}
		else{
			for (int i=1;i<=2*n;i++)s[i]=i%2+'0';
			len=2*n;
		}
		for (int i=1;i<=len;i++)putchar(s[i]);
		cout<<endl;
	}
	return 0;
}