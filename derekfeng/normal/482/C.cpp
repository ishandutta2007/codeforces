#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
map<int,int>mp;
int n,m,miko[1100000];
int bad[1100000];
ll num[55][22],a[1100000];
string s[55];
double dp[1100000];
double go(int masks){
	if (bad[masks]==0) return 0.0;
	if (dp[masks]>0.0) return dp[masks];
	dp[masks]=1.0;
	int lft=miko[masks];
	double lf=1.0/double(m-lft);
	for (int i=0;i<m;i++){
		if ((1<<i)&masks) continue;
		dp[masks]+=go(masks|(1<<i))*(double)(bad[masks|(1<<i)])/(double)(bad[masks])*lf;
	}
	return dp[masks];
}
int main(){
	read(n);
	for (int i=0;i<n;i++)
		reads(s[i]);
	m=s[0].size();
	for (int i=0;i<m;i++) mp[1<<i]=i;
	for (int i=0;i<(1<<m);i++)
		miko[i]=__builtin_popcount(i);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++) if(j!=k && s[j][i]==s[k][i]) 
				num[j][i]|=(1ll<<k);
	if(n>1)bad[0]=n;
	for (int i=0;i<n;i++){
		memset (a,0,sizeof(a));
		a[0]=((1ll<<n)-1)^(1ll<<i);	
		for (int j=1;j<(1<<m);j++){
			int val=mp[j&-j];
			a[j]=a[j-(j&-j)]&num[i][val];
			if (a[j]!=0) bad[j]++;
		}
	}
	printf("%.11lf",go(0));
}