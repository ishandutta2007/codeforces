#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std; 
int n,x,y;
char s[1000005];
int pre0[1000005],pre1[1000005],suf0[1000005],suf1[1000005];
int _pre[1000005],_suf[1000005],now,ans;
inline void pre_work(){
	for (register int i=1;i<=n;i++){
		pre0[i]=pre0[i-1],pre1[i]=pre1[i-1],_pre[i]=_pre[i-1];
		if (s[i]=='0')pre0[i]++,_pre[i]++;
		if (s[i]=='1')pre1[i]++;
		if (s[i]=='?')pre1[i]++,_pre[i]++;
	}
	for (register int i=n;i>=1;i--){
		suf0[i]=suf0[i+1],suf1[i]=suf1[i+1],_suf[i]=_suf[i+1];
		if (s[i]=='0')suf0[i]++,_suf[i]++;
		if (s[i]=='1')suf1[i]++;
		if (s[i]=='?')suf0[i]++,_suf[i]++;
	}
	for (register int i=1;i<=n;i++)
		if (s[i]=='1')now+=_pre[i-1]*x+_suf[i+1]*y;
	return;
}
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	cin>>x>>y;
	if (x<y){
		swap(x,y);
		for (register int i=1;i<=n/2;i++)swap(s[i],s[n-i+1]);
	}
	pre_work();
	ans=now;
	for (register int i=1;i<=n;i++){
		if (s[i]=='?'){
			now-=suf1[i+1]*x+pre1[i-1]*y;
			now+=pre0[i-1]*x+suf0[i+1]*y;
			ans=min(ans,now); 
		} 
	}
	cout<<ans<<endl;
	return 0;
}