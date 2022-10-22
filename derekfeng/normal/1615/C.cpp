#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[100004],t[100005];
void sol(){
	scanf("%d%s%s",&n,s,t);
	bool ok=1;
	for(int i=0;i<n;i++)ok&=(s[i]==t[i]);
	if(ok){puts("0");return;}
	bool f1=1,f2=1;
	for(int i=0;i<n;i++){
		f1&=(s[i]=='0');
		f2&=(t[i]=='0');
	}
	if(f1||f2){puts("-1");return;}
	int ans=n+n+2;
	for(int i=0;i<2;i++){
		if(i==1)
			for(int j=0;j<n;j++)
				s[j]=s[j]^'0'^'1';
		int cnt0=0,cnt1=0;
		for(int j=0;j<n;j++)if(t[j]!=s[j]){
			if(t[j]=='0')cnt0++;
			if(t[j]=='1')cnt1++;
		}
		if((cnt1-cnt0)>1||(cnt1-cnt0)<0)continue;
		if(((cnt1+cnt0)&1)!=i)continue;
		ans=min(ans,cnt0+cnt1);
	}
	if(ans==n+n+2)puts("-1");
	else printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}