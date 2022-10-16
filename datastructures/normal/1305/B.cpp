#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1005];
int n,pre[1005],nxt[1005];
inline void work(int now,int opt,int rest){
	if (opt==1){
		for (int i=1;i<=now;i++)
			if (s[i]=='('&&rest)cout<<i<<' ',rest--;
	}
	else{
		int i;
		for (i=now;i<=n;i++)
			if (nxt[i]<rest)break;
		i--;
		for (;i<=n;i++)
			if (s[i]==')'&&rest)cout<<i<<' ',rest--;
	}
	return;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='(');
	for (int i=n;i>=1;i--)nxt[i]=nxt[i+1]+(s[i]==')');
	int mx=0,id=0;
	for (int i=1;i<=n;i++)
		if (min(pre[i],nxt[i])>mx)mx=min(pre[i],nxt[i]),id=i;
	if (id==0){
		puts("0");
		return 0;
	}
	cout<<1<<endl;
	cout<<mx*2<<endl;
	work(id,1,mx);
	work(id,2,mx);
	cout<<endl;
	return 0;
}