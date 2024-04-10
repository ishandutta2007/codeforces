#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define ll long long
using namespace std;
int n,cnt[23][26];
char s[20005];
int awa[8388608],qwq[8388608][26];
int f[8388608];
ll ans;
int lowbit(int x){
	return x&(-x);
}
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (int j=1;j<=len;j++)cnt[i][s[j]-'a']++;
	}
	for (int i=1;i<(1<<n);i++){
		awa[i]=awa[i-lowbit(i)]+1;
		int j=0;
		while((i&(1<<j))==0)j++;
		if (i==(1<<j)){
			for (int k=0;k<26;k++)
				qwq[i][k]=cnt[j][k];
		}
		else{
			for (int k=0;k<26;k++)
				qwq[i][k]=min(cnt[j][k],qwq[i^(1<<j)][k]);
		}
		int ans=1;
		for (int k=0;k<26;k++)ans=1ll*ans*(qwq[i][k]+1)%mod;
		if (awa[i]&1)f[i]=ans;
		else f[i]=mod-ans;
	}
	for (int i=0;i<n;i++)
		for (int j=1;j<(1<<n);j++)
			if (j&(1<<i))upd(f[j],f[j^(1<<i)]);
	for (int i=1;i<(1<<n);i++){
		int s=0;
		for (int j=0;j<n;j++)
			if (i&(1<<j))s+=j+1;
		ans^=1ll*f[i]*s*awa[i];
	}
	cout<<ans<<endl;
	return 0;
}