#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
char s[maxn];
int k;
int main(){
	scanf("%s",s);
	scanf("%d",&k);
	int n = strlen(s)-1;
	for (;k;k--){
		if (s[n]=='0'){
			s[n--] ='\0';
		}else{
			s[n]--;
		}
	}	
	printf("%s\n",s);
	return 0;
}