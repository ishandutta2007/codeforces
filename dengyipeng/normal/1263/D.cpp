#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 300005
using namespace std;

int n,i,j,k,fa[maxn],ans,bz[30];
char ch;

int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}

void Link(int x,int y){
	x=father(x),y=father(y);
	fa[x]=y;	
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n+26;i++) fa[i]=i; 
	for(i=1;i<=n;i++){
		for(ch=getchar();ch<'a'||ch>'z';ch=getchar());	
		for(;ch>='a'&&ch<='z';ch=getchar())
			Link(i,ch-'a'+1+n),bz[ch-'a'+1]=1;
	}
	for(i=1;i<=26;i++) if (bz[i]&&father(n+i)==n+i) 
		ans++;
	printf("%d",ans);
}