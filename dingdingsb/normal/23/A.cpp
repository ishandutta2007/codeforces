#include<bits/stdc++.h>
using namespace std;
char str[200];
int ans=0;
int main(){
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;i++)
		for(int j=i+1;j<=len;j++){
			int Len=-1;
			while(str[i+Len+1]==str[j+Len+1]&&j+Len<=len)
				Len++;
			ans=max(Len+1,ans);
				
		}
	printf("%d",ans);
}