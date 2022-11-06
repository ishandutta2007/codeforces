#include<bits/stdc++.h>
using namespace std;
bool a[300];
char s[55];
int main(){
	int T;
	int n,i,j,k;
	scanf("%d",&T);
	while(T--){
		bool flg=1;
		scanf("%d%s",&n,s);memset(a,0,sizeof(a));
		for(i=0;s[i];){
			if(a[s[i]]){
				puts("NO");
				flg=0;
				break;
			}
			a[s[i]]=1;
			for(j=i;s[j]==s[i]&&s[j];++j);
			i=j;
		}
		if(flg)puts("YES");
	}
	return 0;
}