#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
char s[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int cnt=0; bool flag=1;
		if(s[n]=='A') flag=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='A') ++cnt;
			else{
				if(cnt==0){
					flag=0; break;
				}
				--cnt;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}