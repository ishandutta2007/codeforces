#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define ll long long
#define maxV 1000000
using namespace std;
int n,a[1005];
map<int,int> qwq;
int qaq[1000005],pos[1000005],num;
int tot,s[1000005];
int totm=1,u[2000005],v[2000005],w[2000005],first[2000005],nxt[2000005];
void add_edge(int x,int y,int z){
	int i=++totm;
	u[i]=x,v[i]=y,w[i]=z;
	nxt[i]=first[u[i]],first[u[i]]=i;
	i=++totm;
	u[i]=y,v[i]=x,w[i]=0;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int last,d[1005];
ll ans;
int head,tail,q[2000005],awa[2000005];
int bfs(){
	head=1,tail=0;
	memset(awa,-1,sizeof(awa));
	for (int i=1;i<=n;i++)
		if (d[i]>0)q[++tail]=i,awa[i]=0;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=first[now];i;i=nxt[i])
			if (w[i^1]>0&&awa[v[i]]==-1)awa[v[i]]=(i^1),q[++tail]=v[i];
	}
	for (int i=last+1;i<=n+tot;i++)
		if (awa[i]!=-1)return i;
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		qaq[a[i]]++;
		if (pos[a[i]]==0)pos[a[i]]=i;
		for (int j=2;j<=n;j++)qwq[a[i]*j]=1;
	}
	for (map<int,int>::iterator it=qwq.begin();it!=qwq.end();it++){
		int val=(*it).first;
		if (val<=maxV&&qaq[val]>0){
			qwq[val]=0;
			continue;
		}
		s[++tot]=val;
		qwq[val]=tot;
	}
	for (int i=1;i<=1000000;i++){
		if (qaq[i]==0)continue;
		ans+=i;
		qaq[i]--;
		if (qaq[i]==0)continue;
		num+=qaq[i];
		d[pos[i]]=qaq[i];
		for (int j=1;j<=n;j++)
			if (qwq[i*j]!=0)add_edge(n+qwq[i*j],pos[i],qaq[i]);
	}
	last=n;
	for (int i=1;i<=num;i++){
		int x=bfs();
		last=x;
		ans+=s[x-n];
		while(awa[x]!=0){
			int id=awa[x];
			w[id]--,w[id^1]++;
			x=v[id];
		}
		d[x]--;
	}
	cout<<ans<<endl;
	return 0;
}