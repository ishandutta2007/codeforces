#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;

int q,s[maxn],t[maxn],len,n,m,i,j,k,bz[30];
char ch;

int main(){
	scanf("%d",&q);
	ch=getchar();
	while (q--){
		for(;ch<'a'||ch>'z';ch=getchar());
		memset(bz,0,sizeof(bz));
		len=0;
		for(;ch>='a'&&ch<='z';ch=getchar())
			s[++len]=ch-'a',bz[ch-'a']=1;
		len=0;
		for(;ch<'a'||ch>'z';ch=getchar());
		for(;ch>='a'&&ch<='z';ch=getchar())
			t[++len]=ch-'a';
		int tp=1;
		for(i=1;i<=len;i++) if (bz[t[i]])
			{printf("YES\n");tp=0;break;}
		if (tp) printf("NO\n");
	}
}