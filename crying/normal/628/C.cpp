#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
char str[MAXN],ans[MAXN];
int len,k;
int main(){
	scanf("%d%d",&len,&k);
	scanf("%s",str+1);
	for(int i=1;i<=len;i++){
		int maxd=max(str[i]-'a','z'-str[i]);
		if(maxd<=k){
			k-=maxd;
			if(str[i]-'a'==maxd){
				ans[i]='a';
			}else{
				ans[i]='z';
			}
		}else{
			if(str[i]-k>='a'){
				ans[i]=str[i]-k;
			}else{
				ans[i]=str[i]+k;
			}
			k=0;
		}
	}
	if(k){
		printf("-1");
	}else{
		printf("%s",ans+1);
	}
	return 0;
}