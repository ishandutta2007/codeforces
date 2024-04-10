#include <bits/stdc++.h>
using namespace std;
int T,n,m,s1,s2,a[1003],b[1003];
bitset<1000003>f[1003];
int d[2][2][1003],cnt[2][2];
int D[2][1003];
int t[2];
bool crok;
void sol(){
	scanf("%d",&n);s1=s2=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s1+=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),s2+=b[i];
	if((s1&1)||(s2&1)||(n!=m)){
		puts("No");
		return;
	}
	memset(cnt,0,sizeof(cnt));
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	f[0].reset(),f[0][0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]|f[i-1]<<a[i];
	if(!f[n][s1>>1]){
		puts("No");
		return;
	}
	for(int i=n,s=s1>>1;i;i--){
		if(s>=a[i]&&f[i-1][s-a[i]])s-=a[i],d[0][0][++cnt[0][0]]=a[i];
		else d[0][1][++cnt[0][1]]=a[i];
	}
	f[0].reset(),f[0][0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]|f[i-1]<<b[i];
	if(!f[n][s2>>1]){
		puts("No");
		return;
	}
	for(int i=n,s=s2>>1;i;i--){
		if(s>=b[i]&&f[i-1][s-b[i]])s-=b[i],d[1][0][++cnt[1][0]]=b[i];
		else d[1][1][++cnt[1][1]]=b[i];
	}
	t[0]=t[1]=0;
	crok=cnt[0][0]>cnt[1][0];
	for(int i=1;i<=cnt[crok][0];i++)D[0][++t[0]]=d[crok][0][i];
	for(int i=1;i<=cnt[crok][1];i++)D[0][++t[0]]=-d[crok][1][i];
	for(int i=cnt[crok^1][0];i;i--)D[1][++t[1]]=d[crok^1][0][i];
	for(int i=cnt[crok^1][1];i;i--)D[1][++t[1]]=-d[crok^1][1][i];
	int X=0,Y=0;
	puts("Yes");
	for(int i=1;i<=n;i++){
		X+=D[0][i];
		if(!crok)printf("%d %d\n",X,Y);
		else printf("%d %d\n",Y,X);
		Y+=D[1][i];
		if(!crok)printf("%d %d\n",X,Y);
		else printf("%d %d\n",Y,X);
	}
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}