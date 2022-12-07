#include<bits/stdc++.h>
#define ll long long
#define N 2500
using namespace std;
int n,q,f[27][2500];
char S[N];
vector<int>ps[27];
int s[27][2500];
int main(){
	int i,j,k;
	scanf("%d",&n);
	scanf("%s",S+1);
//	for(k=0;k<26;k++)ps[k].push_back(0);
	for(i=1;i<=n;i++)ps[S[i]-'a'].push_back(i);
	for(k=0;k<26;k++)ps[k].push_back(n);
	for(i=1;i<=n+1;s[i==n+1?26:S[i]-'a'][i]++,i++)
		for(k=0;k<26;k++)s[k][i]=s[k][i-1];
	scanf("%d",&q);
	for(k=0;k<26;k++){
		for(int ii=0;ii<ps[k].size();ii++){
			int len=1,ans=0;i=ps[k][ii];
			for(j=n;j;j--){
				while(len<=i&&i-j>len-1+s[k][i]-s[k][len-1])++len;
				f[k][j]=max(f[k][j],i-len+1);
			}
		}
	}
	for(i=1;i<=n/2;i++)swap(S[i],S[n-i+1]);
	for(k=0;k<26;k++)ps[k].clear();
	for(i=1;i<=n;i++)ps[S[i]-'a'].push_back(i);
	for(k=0;k<26;k++)ps[k].push_back(n);
	for(i=1;i<=n+1;s[i==n+1?26:S[i]-'a'][i]++,i++)
		for(k=0;k<26;k++)s[k][i]=s[k][i-1];
	for(k=0;k<26;k++){
		for(int ii=0;ii<ps[k].size();ii++){
			int len=1,ans=0;i=ps[k][ii];
			for(j=n;j;j--){
				while(len<=i&&i-j>len-1+s[k][i]-s[k][len-1])++len;
				f[k][j]=max(f[k][j],i-len+1);
			}
		}
	}
	while(q--){
		int m;char c;
		scanf("%d %c",&m,&c);
		printf("%d\n",f[c-'a'][m]);
	}
	return 0;
}