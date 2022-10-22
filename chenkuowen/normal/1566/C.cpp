#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int s[2][N],f[N];
char ss[2][N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int j=0;j<2;++j) scanf("%s",ss[j]+1);
		for(int i=1;i<=n;++i) 
			for(int j=0;j<2;++j)
				s[j][i]=s[j][i-1]+int(ss[0][i]-'0'==j)+int(ss[1][i]-'0'==j);
		int p1=0,p2=0;
		f[0]=0;
		for(int i=1;i<=n;++i){
			while(p1+1<i&&s[0][i]-s[0][p1+1]>0&&s[1][i]-s[1][p1+1]>0) ++p1;
			while(p2+1<i&&s[0][i]-s[0][p2+1]>0) ++p2;
			f[i]=0;
			if(s[0][i]-s[0][p1]>0&&s[1][i]-s[1][p1]>0) f[i]=max(f[i],f[p1]+2);
			if(s[0][i]-s[0][p2]>0) f[i]=max(f[i],f[p2]+1);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}