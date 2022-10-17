#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
struct accept{
	int son[26],fail,nowval,val;
	accept(){
		memset(son,0,sizeof(son));
		fail=val=0;
		return;
	}
}a[100005];
int num,len,cnt;
int n,tot,nxt[15][1005],val[15][1005],f[1005][17005]; 
char t[1005],s[400005];
inline void build(){
	int now=0;
	for (int i=1;i<=len;i++){
		if (a[now].son[t[i]-'a']==0)a[now].son[t[i]-'a']=++cnt;
		now=a[now].son[t[i]-'a'];
	}
	int val;
	cin>>val;
	a[now].nowval+=val;
	return;
}
int head,tail,q[1005];
inline void build_fail(){
	head=1,tail=0;
	for (int i=0;i<26;i++)
		if (a[0].son[i]!=0)q[++tail]=a[0].son[i];
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=0;i<26;i++)
			if (a[now].son[i]!=0){
				a[a[now].son[i]].fail=a[a[now].fail].son[i];
				q[++tail]=a[now].son[i];
			}
			else a[now].son[i]=a[a[now].fail].son[i];
	}
	return;
}
inline int dfs(register int now,register int nowa,register int nowb){
	if (now>tot)return 0;
	if (f[nowa][nowb]!=-1e18)return f[nowa][nowb];
	if (now==0)return val[0][0]+dfs(now+1,nxt[0][0],nowb);
	register int s=-1e18;
	for (register int i=0;i<14;i++){
		if ((nowb&(1<<i))!=0)continue;
		register int x=a[nowa].son[i];
		s=max(s,a[x].val+val[now][x]+dfs(now+1,nxt[now][x],nowb|(1<<i)));
	}
	return f[nowa][nowb]=s;	
}
signed main(){
	cin>>num;
	for (int i=1;i<=num;i++){
		scanf("%s",t+1);
		len=strlen(t+1);
		build();
	}
	build_fail();
	for (int i=1;i<=cnt;i++)
		for (int j=i;j;j=a[j].fail)	
			a[i].val+=a[j].nowval;
	scanf("%s",s+1);
	n=strlen(s+1);
	tot=-1;
	for (register int i=0;i<=n;){
		++tot;
		register int k;
		for (register int j=0;j<=cnt;j++){
			register int now=j,nowval=0;
			for (k=i+1;s[k]!='?'&&k<=n;k++){
				now=a[now].son[s[k]-'a'];
				nowval+=a[now].val;
			}
			nxt[tot][j]=now,val[tot][j]=nowval;
		}
		i=k;
	}
	for (register int i=0;i<=1000;i++)
		for (register int j=0;j<=17000;j++)
				f[i][j]=-1e18;
	cout<<dfs(0,0,0)<<endl;
	return 0;
}