#include<bits/stdc++.h>
using namespace std;
char s[305][305];
int cnt[3][2];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
			for(int j=1;j<=n;++j){
				if(s[i][j]=='O') 
					cnt[(i+j)%3][0]++;
				if(s[i][j]=='X')
					cnt[(i+j)%3][1]++;
			}
		}
		int k=0;
		for(int t=1;t<3;++t){
			if(cnt[t][0]+cnt[(t+1)%3][1]<
				cnt[k][0]+cnt[(k+1)%3][1])
				k=t;
		}
		int ss=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if((i+j)%3==k&&s[i][j]=='O') s[i][j]='X';
				if((i+j)%3==(k+1)%3&&s[i][j]=='X') s[i][j]='O';
			}
		for(int i=1;i<=n;++i)
			printf("%s\n",s[i]+1);
	}
	return 0;
}