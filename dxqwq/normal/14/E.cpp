#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long ans[23][13][13][4][4],Ans;
signed main()
{
    int n=read(),t=read();
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) if(i!=j) ans[2][0][0][i][j]=1;
	for(int q=3; q<=n; q++) for(int i=0; i<4; i++) for(int j=0; j<4; j++) for(int k=0; k<4; k++)
	if(i<j&&j>k) for(int l=1; l<=t; l++) for(int m=0; m<t; m++) ans[q][l][m][j][k]+=ans[q-1][l-1][m][i][j]; 
	else if(i>j&&j<k) for(int l=0; l<=t; l++) for(int m=1; m<t; m++) ans[q][l][m][j][k]+=ans[q-1][l][m-1][i][j]; 
	else if(i!=j&&j!=k) for(int l=0; l<=t; l++) for(int m=0; m<t; m++) ans[q][l][m][j][k]+=ans[q-1][l][m][i][j]; 		
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) Ans+=ans[n][t][t-1][i][j];
	printf("%lld\n",Ans);
    return 0;
}