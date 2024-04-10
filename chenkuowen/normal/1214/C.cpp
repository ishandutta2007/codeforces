#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
char s[MAX_N];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=0,flag=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='(')
			++cnt;
		else{
			if(cnt>0) --cnt;
			else if(flag){
				puts("No");
				return 0;
			}else flag=1;
		}
	if(cnt!=flag) puts("No");
	else puts("Yes");
	return 0;
}