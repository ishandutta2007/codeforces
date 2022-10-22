    #include<cstdio>
    typedef long long ll;
    const int N=2003,M=1e9+7;
    int n,m,f0[N][N],f1[N][N],p0[N][N],p1[N][N];char a[N][N];
    int main(){
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
    	if(a[n][m]=='R')return 0*puts("0");
    	if(n==1&&m==1)return 0*puts("1");
    	for(int i=1,k;i<=n;i++){
    	  k=0;
    	  for(int j=m;j;j--)if(a[i][j]=='R')
    		p0[i][++k]=j;
    	}
    	for(int j=1,k;j<=m;j++){
    	  k=0;
    	  for(int i=n;i;i--)if(a[i][j]=='R')
    		p1[j][++k]=i;
    	}
    	f0[1][1]=f1[1][1]=1;
    	for(int i=1;i<=n;i++)
    	  for(int j=1;j<=m;j++){
    		if(i==1&&j==1)continue;
    		f0[i][j]=((ll)f1[i-1][j]-f1[i-1][j-1]-(p1[j][n-i+1]?f1[p1[j][n-i+1]-1][j]-f1[p1[j][n-i+1]-1][j-1]:0)+M+M)%M;
    		f1[i][j]=((ll)f0[i][j-1]-f0[i-1][j-1]-(p0[i][m-j+1]?f0[i][p0[i][m-j+1]-1]-f0[i-1][p0[i][m-j+1]-1]:0)+M+M)%M;
    		if(i==n&&j==m)printf("%d\n",(f0[i][j]+f1[i][j])%M);
    		f0[i][j]=((ll)f0[i][j]+f0[i][j-1]+f0[i-1][j]-f0[i-1][j-1]+M)%M;
    		f1[i][j]=((ll)f1[i][j]+f1[i][j-1]+f1[i-1][j]-f1[i-1][j-1]+M)%M;
    	  }
    	return 0;
    }