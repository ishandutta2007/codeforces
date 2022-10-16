#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
int n,m,p;
int c[65],tot,a[200005],f[200005],mx,ans[65];
char s[200005][65];
int main(){
	srand(time(NULL));
	cin>>n>>m>>p;
	for (register int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for (register int T=1;T<=40;T++){
		register int now=(rand()*rand()+rand())%n+1;
		tot=0;
		for (register int i=1;i<=m;i++)
			if (s[now][i]=='1')c[tot++]=i; 
		memset(a,0,sizeof(a)); 
		for (register int i=1;i<=n;i++)
			for (register int j=0;j<tot;j++)
				if (s[i][c[j]]=='1')a[i]+=(1<<j);
		memset(f,0,sizeof(f));
		for (register int i=1;i<=n;i++)f[a[i]]++;
		for (register int i=0;i<15;i++)
			for (register int j=0;j<32768;j++)
				if ((j&(1<<i))==0)f[j]+=f[j^(1<<i)];
		for (register int i=0;i<32768;i++){
			if (f[i]<(n+1)/2)continue;
			register int cnt=0;
			for (register int j=0;j<15;j++)
				if ((i&(1<<j)))cnt++;
			if (cnt>mx){
				mx=cnt;
				memset(ans,0,sizeof(ans));
				for (register int j=0;j<tot;j++)
					if ((i&(1<<j)))ans[c[j]]=1;
			}
		}
	}
	for (register int i=1;i<=m;i++)cout<<ans[i];
	cout<<endl;
	return 0;
}