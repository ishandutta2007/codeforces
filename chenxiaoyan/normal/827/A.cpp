#include<bits/stdc++.h>
using namespace std;
#define N 1000000
char ans[2*N+10],s[N+10];
int fa[2*N+1];
int ance(int x){return fa[x]==x?x:fa[x]=ance(fa[x]);}
int main(){
	int n=0,m,i;scanf("%d",&m);
	for(i=1;i<=2*N;i++)fa[i]=i,ans[i]='a';
	while(m--){
		int x,len;scanf("%s%d",s+1,&x);len=strlen(s+1);
		while(x--){
			int y;scanf("%d",&y);n=max(n,y+len-1);
			for(i=ance(y);i<=y+len-1;i=fa[i]=ance(fa[i+1]))
				ans[i]=s[i-y+1];
		}
	}
	ans[n+1]=0;printf(ans+1);
	return 0;
}
/*1
3
a 4 1 3 5 7
ab 2 1 5
ca 1 4
*/
/*2
1
a 1 3
*/
/*3
3
ab 1 1
aba 1 3
ab 2 3 5
*/