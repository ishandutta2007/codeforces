#include<cstdio>
bool a[26];char c;int s;
int main(){
	while(~(c=getchar()))if(c<123&&c>96)a[c-97]=1;
	for(int i=0;i<26;i++)s+=a[i];
	printf("%d",s);
	return 0;
}