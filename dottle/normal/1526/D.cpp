#include<bits/stdc++.h>
#define int long long 
const int N=1000500,M=6;
using namespace std;

int a[N],n,t,c[M],mp[N],ans,v[M],b[M],as[M],L[M],nw[M];
char s[N],p[M];

void dfs(int k){
	if(k==5){
		int na=0;
		memset(nw,0,sizeof(nw));
		for(int i=1;i<=4;i++)
			L[b[i]]=i;
		for(int j=1;j<=n;j++){
			for(int i=1;i<L[a[j]];i++)
				na+=nw[i];
			nw[L[a[j]]]++;
		}
		if(na<ans)
			memcpy(as,b,sizeof(b)),ans=na;
	}else for(int i=1;i<=4;i++)
		if(!v[i])v[i]=1,b[k]=i,dfs(k+1),v[i]=0;
}

main(){
	ios::sync_with_stdio(false);
	mp['A']=1,mp['N']=2,mp['T']=3,mp['O']=4;
	p[1]='A',p[2]='N',p[3]='T',p[4]='O';
	cin>>t;
	while(t--){
		cin>>s+1;
		n=strlen(s+1);
		ans=1e18;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
			a[i]=mp[s[i]],c[a[i]]++;
		dfs(1);
		for(int i=1;i<=4;i++)
			for(int j=1;j<=c[as[i]];j++)
				putchar(p[as[i]]);
		putchar('\n');
	} 
}