#include <bits/stdc++.h>
using namespace std;
const int INF=1e4;
vector<string>pri;
string s;
int X,n;
bool check(string cur){
	for(int i=0;i<cur.size();i++){
		int sum=0;
		for(int j=i;j<cur.size();j++){
			sum+=cur[j]-'0';
			if(sum<X&&X%sum==0)return 0;
		}
	}
	return 1;
}
void generate(string cur,int sum){
	if(sum==X){
		if(check(cur))pri.push_back(cur);
		return;
	}
	for(int i=1;i<10&&sum+i<=X;i++)generate(cur+(char)(i+'0'),sum+i);
}
int cnt,nxt[100000][10],fal[100000];
bool flg[100000];
void add(string s){
	int cur=0;
	for(int i=0;i<s.size();i++){
		if(!nxt[cur][s[i]-'0'])nxt[cur][s[i]-'0']=++cnt;
		cur=nxt[cur][s[i]-'0'];
	}
	flg[cur]=1;
}
void getnxt(){
	queue<int>que;
	for(int i=1;i<10;i++)if(nxt[0][i]){
		fal[nxt[0][i]]=0;
		que.push(nxt[0][i]);
	}
	while(!que.empty()){
		int u=que.front();que.pop();
		for(int i=1;i<10;i++){
			if(nxt[u][i]){
				fal[nxt[u][i]]=nxt[fal[u]][i]; 
				que.push(nxt[u][i]);
			}
		}
		for(int i=1;i<10;i++)if(nxt[u][i]<1)nxt[u][i]=nxt[fal[u]][i];
	}
}
int main(){
	cin>>s>>X,n=s.size();
	generate("",0);
	for(int i=0;i<pri.size();i++)add(pri[i]);
	getnxt();
	vector<int>dp(cnt+1,INF);
	dp[0]=0; 
	for(int i=0;i<n;i++){
		vector<int>dps(cnt+1,INF);
		for(int j=0;j<=cnt;j++)if(dp[j]<INF){
			dps[j]=min(dps[j],dp[j]+1);
			if(!flg[nxt[j][s[i]-'0']])dps[nxt[j][s[i]-'0']]=min(dps[nxt[j][s[i]-'0']],dp[j]);
		}
		swap(dp,dps);
	}
	cout<<(*min_element(dp.begin(), dp.end())); 
}