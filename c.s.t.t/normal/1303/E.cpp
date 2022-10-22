#include<bits/stdc++.h>
using namespace std;
int T_T,S,T,f[410];
char s[410],t[410];
bool ok;
int main(){
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%s%s",s,t),S=strlen(s),T=strlen(t);
		for(int k=0;k<=T;k++){
			memset(f,-1,sizeof(f));
			f[0]=0;
			for(int i=0;i<S;i++){
				for(int j=min(i+1,k);j>=0;j--){
					if(f[j]!=-1&&t[k+f[j]]==s[i])f[j]++;
					if(j&&f[j-1]!=-1&&t[j-1]==s[i])f[j]=max(f[j],f[j-1]);
					f[j]=min(f[j],T-k);
				}
//				for(int j=0;j<=min(i+1,k);j++)printf("%d ",f[j]);puts("");
			}
			ok=false;
			for(int i=0;i<=k;i++)if(f[i]!=-1&&i+f[i]>=T){ok=true;break;}
			if(ok)break;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}