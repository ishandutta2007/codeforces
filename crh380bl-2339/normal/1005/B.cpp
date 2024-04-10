#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char a[200005],b[200005];
int main(){
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	int i,j;
	for(i=n,j=m;a[i]==b[j]&&i>=1&&j>=1;--i,--j);
	printf("%d\n",i+j);
	return 0;
}