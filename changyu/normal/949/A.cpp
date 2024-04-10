#include<cstdio>
#include<cstring>
#include<vector>
const int N=2e5+3;
int n,p[2][N],f[N],k;char a[N];
std::vector<int>ans[N];
int Find(int k,int*p){return p[k]==k?k:p[k]=Find(p[k],p);}
int main(){
	scanf("%s",a+1),n=strlen(a+1);
	p[0][n+1]=p[1][n+1]=n+1;
	for(int i=n;i;i--){
	  p[0][i]=a[i]=='0'?p[0][i+1]:i;
	  p[1][i]=a[i]=='1'?p[1][i+1]:i;
	}
	for(int i=1;i<=n;i++)if(!f[i]){
	  ++k;
	  for(int j=i;j!=n+1;){
		f[j]=1,ans[k].push_back(j);
		if(a[j]=='1')p[0][j]=Find(j+1,p[0]);
		if(a[j]=='0')p[1][j]=Find(j+1,p[1]);
		j=Find(j,p[a[j]-'0']);
	  }
	  if(a[ans[k][0]]=='1'||a[ans[k][ans[k].size()-1]]=='1')return 0*puts("-1");
	}
	printf("%d\n",k);
	for(int i=1;i<=k;i++){
	  printf("%d",ans[i].size());
	  for(int j=0;j<ans[i].size();j++)printf(" %d",ans[i][j]);
	  puts("");
	}return 0;
}