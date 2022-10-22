#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> plii;
#define mkp make_pair
#define fi first
#define se second
int n,m,a,b,num[1003][1003],s,t,deq[1003],am[1003];
int dat[1003][1003],minst[1003][1003];
ll cnt[1003][1003],dp[1003][1003],vis[1003][1003];
vector<plii> answers;
void init(){
	s=0,t=0;
}
void push_(int index_,int x){
	while (s<t && am[t-1]>=x) t--;
	deq[t]=index_,am[t++]=x;
}
void pop_(int index_){
	if (deq[s]==index_) s++;
}
int get_(){
	return am[s];
}
priority_queue <plii,vector<plii>,greater<plii> > q;
int main(){
	cin>>n>>m>>a>>b;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&num[i][j]); 
	for (int i=1;i<=n;i++){
		init();
		for (int j=1;j<=m;j++){
			push_(j,num[i][j]);
			if (j-b>=1) pop_(j-b);
			if (j>=b) dat[i][j-b+1]=get_();
		}
	}
	for (int i=1;i<=m-b+1;i++){
		init();
		for (int j=1;j<=n;j++){
			push_(j,dat[j][i]);
			if (j-a>=1) pop_(j-a);
			if (j>=a) minst[j-a+1][i]=get_(); 
		}
	}
	for (int i=1;i<=n;i++){
		ll now=0;
		for (int j=1;j<b;j++) now+=num[i][j];
		for (int j=b;j<=m;j++){
			now+=num[i][j];
			if (j>b) now-=num[i][j-b]; 
			cnt[i][j-b+1]=now;
		}
	}
	for (int j=1;j<=m-b+1;j++){
		ll num=0;
		for (int i=1;i<a;i++)num+=cnt[i][j];
		for (int i=a;i<=n;i++){
			num+=cnt[i][j];
			if (i>a) num-=cnt[i-a][j]; 
			dp[i-a+1][j]=num;
		}
	}
	for (int i=1;i<=n-a+1;i++) for(int j=1;j<=m-b+1;j++)
		q.push(mkp(dp[i][j]-1ll*minst[i][j]*a*b,mkp(i,j)));  
	while (!q.empty()){
		plii x=q.top();q.pop();
		if (vis[x.se.fi][x.se.se]) continue;
		answers.push_back(x);
		for (int i=x.se.fi-a+1;i<=x.se.fi+a-1;i++)
			for (int j=x.se.se-b+1;j<=x.se.se+b-1;j++)
				if (i>=1 && j>=1 && i<=n && j<=m) vis[i][j]=1;
	}
	cout<<answers.size()<<"\n";
	for (int i=0;i<answers.size();i++)
		printf("%d %d %I64d\n",answers[i].se.fi,answers[i].se.se,answers[i].fi);
}