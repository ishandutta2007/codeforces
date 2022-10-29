#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,s[N],ans[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)s[i]=read();
	for(int l=1,r=1;l<=n;l=r+1){
		while(r<n && s[r+1]==s[l])r++;
		if(l==r){puts("-1");return;}
		for(int i=l;i<r;i++)ans[i]=i+1;
		ans[r]=l;
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){	
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}