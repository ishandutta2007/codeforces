#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m,a[100010],b[100010];
int c[100010],d[100010];
int fat[100010];
int find(int x){
	return fat[x]?fat[x]=find(fat[x]):x;
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if (x^y) return fat[y]=x,1;
	return 0;
}
void init(){
}
void solve(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) c[i]=d[i]=0,fat[i]=0;
	for (int i=1;i<=m;i++) a[i]=read(),b[i]=read(),c[a[i]]=i,d[b[i]]=i;
	int ans=0;
	for (int i=1;i<=m;i++){
		if (a[i]==b[i]) continue;
		if (d[a[i]]&&d[a[i]]<i) ans++,merge(i,d[a[i]]);
		if (c[b[i]]&&c[b[i]]<i) ans++,merge(i,c[b[i]]);
	}
	for (int i=1;i<=m;i++) ans+=a[i]!=b[i]&&find(i)==i;
//	for (int i=1;i<=m;i++){
//		if (a[i]==b[i]) continue;
//		ans+=find(i)==i;
//	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
}