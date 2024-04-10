#include<bits/stdc++.h>
using namespace std;
char a[1002][1002],b[1002][1002];
int main(){
	int t,n,j,i;
	bool flg;
	scanf("%d",&t);
	while(t--){
		flg=1;
		scanf("%d",&n);
		for(i=0;i<n;++i)scanf("%s",a[i]);
		for(i=0;i<n;++i)scanf("%s",b[i]);
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				a[i][j]-='0';
				b[i][j]-='0';
				a[i][j]^=b[i][j];
			}
		}
		for(i=1;i<n&&flg;++i){
			for(j=1;j<n;++j){
				if(a[i][j]^a[i][0]^a[0][j]^a[0][0]){
					puts("NO");
					flg=0;
					break;
				}
			}
		}
		if(flg)puts("YES");
	}
	return 0;
}