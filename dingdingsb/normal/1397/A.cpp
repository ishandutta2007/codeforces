#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int t,n;char str[1000+10];
int num[30];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);memset(num,0,sizeof num);
		for(int i=1;i<=n;i++){
			scanf("%s",str+1);
			int len=strlen(str+1);
			for(int j=1;j<=len;j++)
				num[str[j]-'a']++;
		}
		for(int i=0;i<=25;i++)
			if(num[i]%n){
				puts("NO");
				goto loop;
			}
		puts("YES");
		loop:;
	}
	return 0;
}//SJY AK IOI