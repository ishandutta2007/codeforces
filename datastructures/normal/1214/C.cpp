#include <iostream>
#include <cstdio>
using namespace std;
int n,now,mn;
char s[200005];
int main(){
	cin>>n;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='(')now++;
		else now--;
		mn=min(mn,now);
	}
	if (now==0&&mn>=-1)puts("Yes");
	else puts("No");
	return 0;
}