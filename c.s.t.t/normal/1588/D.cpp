#include<bits/stdc++.h>
using namespace std;
int T,n,S[11],f[60][1<<11],g[60][1<<11],h[60][1<<11],mx;
char s[11][200],r[200];
vector<int>v[11][60];
int hs(char c){
	if('a'<=c&&c<='z')return c-'a';
	return c-'A'+26;
}
char sh(int x){
	if(x<26)return 'a'+x;
	return x-26+'A';
}
void mian(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]),S[i]=strlen(s[i]);
		for(int j=0;j<52;j++)v[i][j].clear();
		for(int j=0;j<S[i];j++)v[i][hs(s[i][j])].push_back(j);
	}
	memset(f,-1,sizeof(f)),memset(g,-1,sizeof(g)),memset(h,-1,sizeof(h));
	for(int i=0;i<52;i++){
		bool ok=true;
		for(int j=0;j<n;j++)if(v[j][i].empty())ok=false;
		if(ok)f[i][0]=1;
	}
	for(int I=0;I<S[0];I++){
		int i=hs(s[0][I]);
		for(int j=0;j<(1<<n);j++){
			if(f[i][j]==-1)continue;
//			printf("%d,%d:%d\n",i,j,f[i][j]);
			for(int k=0;k<52;k++){
				int sta=0;
				for(int t=0;t<n;t++){
					auto it=upper_bound(v[t][k].begin(),v[t][k].end(),v[t][i][(j>>t)&1]);
					if(it==v[t][k].end()){sta=-1;break;}
					sta|=(it-v[t][k].begin())<<t;
				}
				if(sta!=-1&&f[k][sta]<f[i][j]+1)
					f[k][sta]=f[i][j]+1,g[k][sta]=i,h[k][sta]=j;
			}
		}
	}
	mx=0;
	for(int i=0;i<52;i++)for(int j=0;j<(1<<n);j++)mx=max(mx,f[i][j]);
	printf("%d\n",mx);
	if(!mx){puts("");return;}
	for(int i=0;i<52;i++)for(int j=0;j<(1<<n);j++)if(mx==f[i][j]){
		for(int t=mx-1;t>=0;t--){
			r[t]=sh(i);
			int I=i,J=j;
			i=g[I][J],j=h[I][J];
		}
		r[mx]=0;
		printf("%s\n",r);
		return;
	}
}
int main(){
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}