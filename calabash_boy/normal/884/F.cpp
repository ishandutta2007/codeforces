#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 400;
int first[maxn*30],from[maxn*60],nxt[maxn*60],des[maxn*60],flow[maxn*60],cost[maxn*60],tot=-1;
int n;
char s[maxn];
int cnt[300];
int val[maxn];
int dis[maxn*60],pre[maxn*60],ss,tt;
bool in[maxn*60];
void input(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		cnt[s[i]]++;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",val+i);
	}
}
inline void addEdge(int x,int y,int f,int c){
	tot ++;
	from[tot] =x;
	des[tot] =y;
	flow[tot] =f;
	cost[tot] =c;
	nxt[tot] = first[x];
	first[x] = tot;
	
	tot++;
	from[tot] =y;
	des[tot] =x;
	flow[tot] =0;
	cost[tot] = -c;
	nxt[tot] = first[y];
	first[y] = tot;
}
void build(){
	memset(first,-1,sizeof first);
	ss =0;tt = 26+14*n+1;
	for (int i=1;i<=26;i++){
		addEdge(ss,i,cnt[i+'a'-1],0);
		for (int j=1;j*2<=n;j++){
			int temp = 26+n/2*(i-1)+j;
			addEdge(i,temp,1,0);
			addEdge(temp,26+13*n+j,1,s[j]-'a'+1==i?val[j]:0);
			addEdge(temp,26+13*n+n+1-j,1,s[n+1-j]-'a'+1==i?val[n+1-j]:0);
		}
	}
	for (int i=1;i<=n;i++){
		addEdge(26+13*n+i,tt,1,0);
	}
}
bool spfa(){
//	cout<<"spfa"<<endl;
	queue<int> Q;
	memset(in,false,sizeof in);
	memset(pre,-1,sizeof pre);
	memset(dis,-INF,sizeof dis);
	Q.push(ss);
	in[ss] = true;
	dis[ss] =0;
	while (!Q.empty()){
		int q = Q.front();Q.pop();
		in[q] = false;
		for (int t = first[q];t!=-1;t = nxt[t]){
			int v = des[t];
			int f = flow[t];
			int c = cost[t];
			if (!f)continue;
			if (dis[v]<dis[q]+c){
				pre[v] = t;
				dis[v] = dis[q]+c;
				if (!in[v]){
					Q.push(v);
					in[v] = true;
				}
			}
		}
	}
	return pre[tt]!=-1;
}
void solve(){
	int totflow =0,totcost =0,nowflow,nowcost;
	while (spfa()){
		nowflow = INF;
		nowcost =0;
		int t = pre[tt];
		while (t!=-1)nowcost+=cost[t],nowflow = min(nowflow,flow[t]),t = pre[from[t]];
		totflow+=nowflow;
		totcost+=nowcost*nowflow;
		t = pre[tt];
		while (t!=-1)flow[t]-=nowflow,flow[t^1]+=nowflow,t = pre[from[t]];
//		cout<<nowflow<<endl;
	}
	cout<<totcost<<endl;
}
int main(){
	input();
	build();
	solve();
	return 0;
}