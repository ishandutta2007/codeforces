#include<cstdio>
const int N=1e5+3;
char a[N];int l,b[10];
int main(){
	scanf("%d%s",&l,a+1);
	for(int i=1;i<=l;i++){
	  if(a[i]=='L'){for(int j=0;;j++)if(!b[j]){b[j]=1;break;}}
	  else if(a[i]=='R'){for(int j=9;;j--)if(!b[j]){b[j]=1;break;}}
	  else b[a[i]-48]=0;
	}for(int i=0;i<10;i++)printf("%d",b[i]);
	return 0;
}