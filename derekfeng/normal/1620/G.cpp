#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,m;
char c[200004];
int cnt[23][26];
int mn[26],f[8400000];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",c),m=strlen(c);
		for(int j=0;j<m;j++)cnt[i][c[j]-'a']++;
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<26;j++)mn[j]=1e9;
		for(int j=0;j<n;j++)if(i>>j&1)
			for(int k=0;k<26;k++)mn[k]=min(mn[k],cnt[j][k]);
		f[i]=__builtin_parity(i)?1:M-1;
		for(int j=0;j<26;j++)f[i]=(ll)f[i]*(mn[j]+1)%M;
	}
	for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)if(j>>i&1)(f[j]+=f[j^(1<<i)])%=M;
	for(int i=1;i<(1<<n);i++){
		int tmp=0;
		for(int j=0;j<n;j++)if(i>>j&1)tmp+=j+1;
		tmp*=__builtin_popcount(i);
		ans^=(ll)tmp*f[i];
	}
	printf("%lld",ans);
}