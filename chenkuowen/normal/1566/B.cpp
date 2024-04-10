#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int s[2][N],f[N];
char ss[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",ss+1);
		int n=strlen(ss+1);
		for(int i=1;i<=n;++i) 
			for(int j=0;j<2;++j)
				s[j][i]=s[j][i-1]+int(ss[i]-'0'==j);
		int p1=0,p2=0;
		f[0]=0;
		for(int i=1;i<=n;++i){
			while(p1<i&&s[0][i]-s[0][p1]>0&&s[1][i]-s[1][p1]>0) ++p1;
			while(p2<i&&s[0][i]-s[0][p2]>0) ++p2;
			f[i]=2;
			if(p1<i) f[i]=min(f[i],f[p1]+1);
			if(p2<i) f[i]=min(f[i],f[p2]+0);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}