#include<bits/stdc++.h>
using namespace std;
int n,q,N;
char s[100004];
int d[10][1000400];
int S[100004],T[100004];
int pre[100004],nxt[100004];
int cur=0,dir=1;
vector<int>v[100004];
void del(int i){
	int P=pre[i],N=nxt[i];
	nxt[P]=N,pre[N]=P;
}
void move(){
	int ncur;++N;
	if(dir==1)S[cur]=min(S[cur],N);
	v[cur].push_back(N);
	for(int i=0;i<10;i++)d[i][N]=d[i][N-1];
	if(isdigit(s[cur])){
		ncur=dir?nxt[cur]:pre[cur];
		d[s[cur]-'0'][N]++;
		if(s[cur]=='0')del(cur);
		else s[cur]--;
	}else{
		dir=(s[cur]=='>');
		ncur=dir?nxt[cur]:pre[cur];
		if(!isdigit(s[ncur])&&1<=cur&&cur<=n)del(cur);
		if(dir==0)T[cur]=min(T[cur],N);
	}
	cur=ncur;
}
set<int>st;
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	s[0]='>',s[n+1]='<';
	for(int i=0;i<=n;i++)pre[i+1]=i,nxt[i]=i+1;
	for(int i=0;i<=n+1;i++)S[i]=1e9;
	while(N<=(n+2)*10)move();
	st.insert(1e9);
	for(int i=1;i<=n;i++){
		for(auto x:v[i-1])st.insert(x);
		T[i]=(*st.lower_bound(S[i]));
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		for(int i=0;i<10;i++)
			printf("%d ",d[i][min(S[r+1]-1,T[l]-1)]-d[i][S[l]-1]);
		puts("");
	}
}