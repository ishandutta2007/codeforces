#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
char a[MAX_N],b[MAX_N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int pos=0,n=strlen(a+1),m=strlen(b+1);
		for(int i=1;i<=m;++i)
			if(b[m-i+1]=='1'){
				pos=i;
				break;
			}
		for(int i=pos;i<=n;++i)
			if(a[n-i+1]=='1'){
				printf("%d\n",i-pos);
				break;
			}
	}
	return 0;
}