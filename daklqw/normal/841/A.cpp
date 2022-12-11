#include<cstdio>
using namespace std;
char s[111];
int a[127]={0};
int main(){
	int n,k;
	scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<n;++i)
	++a[s[i]];
	for(int i='a';i<='z';++i)if(a[i]>k){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}