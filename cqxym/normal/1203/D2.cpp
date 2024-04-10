#include<bits/stdc++.h>
using namespace std;
char s[200001],t[200001];
int a[200001];
int main(){
	scanf("%s",s);
	scanf("%s",t);
	int n=strlen(s),m=strlen(t),i=0,j,ans;
	for(j=0;j<m;j++){
		while(s[i]!=t[j]){
			i++;
		}
		i++;
	}
	ans=n-i;
	i=n-1;
	for(j=m-1;j>-1;j--){
		while(s[i]!=t[j]){
			i--;
		}
		a[j]=i;
		i--;
	}
	ans=max(i+1,ans);
	i=0;
	for(j=1;j<m;j++){
		while(s[i]!=t[j-1]){
			i++;
		}
		ans=max(ans,a[j]-i-1);
		i++;
	}
	printf("%d",ans);
	return 0;
}