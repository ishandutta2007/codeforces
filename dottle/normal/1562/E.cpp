#include<bits/stdc++.h>
const int N=5005;
using namespace std;

int lcp[N][N],f[N],n,t,ans;
char s[N];

bool le(int x,int y){
	if(y+lcp[x][y]>n)return 0;
	return s[x+lcp[x][y]]<s[y+lcp[x][y]]; 
}

main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1),ans=n;
		for(int i=n;i;i--)
			for(int j=n;j;j--)
				if(i==j)
					lcp[i][j]=n-i+1;
				else if(s[i]==s[j])
					lcp[i][j]=lcp[i+1][j+1]+1;
		f[1]=n;
		for(int i=2;i<=n;i++){
			f[i]=n-i+1;
			for(int j=1;j<i;j++)
				if(le(j,i))
					ans=max(f[i]=max(f[i],f[j]+n-i+1-lcp[i][j]),ans);	
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				lcp[i][j]=0;
	}
}