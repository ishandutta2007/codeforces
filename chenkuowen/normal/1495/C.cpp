#include<bits/stdc++.h>
using namespace std;
char s[505][505];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
		for(int k=((n-1)%3==2?2:1);k<=n;k+=3){
			for(int j=1;j<=m;++j)
				s[k][j]='X';
			if(k>3){
				bool flag=0;
				for(int j=1;j<=m;++j){
					if(s[k-1][j]=='X'||s[k-2][j]=='X'){
						s[k-1][j]=s[k-2][j]='X';
						flag=1;
						break;
					}
				}
				if(!flag) s[k-2][1]=s[k-1][1]='X';
			}
		}
		for(int i=1;i<=n;++i)
			printf("%s\n",s[i]+1);
	}
	return 0;
}