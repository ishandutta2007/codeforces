#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000005];
int t,n;
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int fg=1,cnt=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='A')cnt++;
			else cnt--;
			if (cnt<0)fg=0;
		}
		if (s[n]=='A')fg=0;
		if (fg==0)puts("NO");
		else puts("YES");
	}
	return 0;
}