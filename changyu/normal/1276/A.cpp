#include<cstdio>
#include<cstring>
const int N=150003;
char a[N];int n,f[N],ans;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s",a+1);n=strlen(a+1);
	ans=0;
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=5;i<=n;i++)if(a[i-4]=='t'&&a[i-3]=='w'&&a[i-2]=='o'&&a[i-1]=='n'&&a[i]=='e')
	  f[i-2]=1,ans++;//,puts("fasd");
	//for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	//for(int i=3;i<=n;i++)printf("%d %d %d\n",!f[i]&&f[i-1]&&!f[i-2]);puts("");
	for(int i=3;i<=n;i++)if(!f[i]&&!f[i-1]&&!f[i-2]&&(a[i-2]=='t'&&a[i-1]=='w'&&a[i]=='o'||a[i-2]=='o'&&a[i-1]=='n'&&a[i]=='e'))
	  f[i-1]=1,ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)if(f[i])printf("%d ",i);puts("");
	}return 0;
}