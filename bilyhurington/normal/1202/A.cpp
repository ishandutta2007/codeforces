#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int t,na,nb;
char a[100010],b[100010];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s %s",a+1,b+1);
		na=strlen(a+1);
		nb=strlen(b+1);
		int cnt=0;
		for(cnt=nb;cnt>=1;cnt--){
			if(b[cnt]-'0') break;
		}
		cnt=nb-cnt;
		for(int i=na-cnt,j=0;i>=1;i--,j++){
//			printf("%d %d\n",i,a[i]);
			if(a[i]-'0'){
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}