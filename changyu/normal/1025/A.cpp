#include<cstdio>
int l,b[26];char a[100001]; 
int main(){
	scanf("%d%s",&l,a);
	if(l==1)return 0*puts("Yes");
	for(int i=0;i<l;i++){
	  b[a[i]-97]++;
	  if(b[a[i]-97]>1)return 0*puts("Yes");
	}return 0*puts("No");
}