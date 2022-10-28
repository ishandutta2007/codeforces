#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
string stt;
int k;

struct state{
	int len, link;
	map<char, int>next;
};

const int N=1e5+5;
state st[N*2];
int dp[N*2];
bool vis[2*N];
bool che[2*N];
int ans[2*N];
bool che2[2*N];
int sz, last;

void sa_init(){
	st[0].len=0;
	st[0].link=-1;
	sz++;
	last=0;
}

void sa_extend(char c){
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p=last;
	while(p!=-1 && !st[p].next.count(c)){
		st[p].next[c]=cur;
		p=st[p].link;
	}
	if(p==-1){
		st[cur].link=0;
	}
	else{
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len){
			st[cur].link=q;
		}
		else{
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].next=st[q].next;
			st[clone].link=st[q].link;
			while(p!=-1 && st[p].next[c]==q){
				st[p].next[c]=clone;
				p=st[p].link;
			}
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}

void dfs(int v){
	if(che[v]){
		return;
	}
	che[v]=1;
	for(auto u:st[v].next){
		dfs(u.second);
		dp[v]+=dp[u.second];
	}
}

void dfs2(int v){
	if(che2[v]){
		return;
	}
	ans[v]=dp[v];
	che2[v]=1;
	for(auto u:st[v].next){
		dfs2(u.second);
		ans[v]+=ans[u.second];
	}
}
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>stt;
	cin>>k;
	int n=stt.size();
	if(k>((n*(n+1))/2)){
		cout<<"No such line.";
		return 0;
	}
	
	sa_init();
	for(auto ch:stt){
		sa_extend(ch);
	}
	int node=last;
	while(node!=-1){
		dp[node]=1;
		node=st[node].link;
	}
	
	dfs(0);
	
	dfs2(0);
	
	int cnt=0;
	node=0;
	string fin="";
	
	int iter=0;
	
	while(cnt<k){
		iter++;
		
		for(int i=0; i<26; i++){
			if(!st[node].next.count('a'+i)){
				continue;
			}
			if(ans[st[node].next[i+'a']]+cnt<k){
				cnt+=ans[st[node].next[i+'a']];
			}
			else{
				fin+=(i+'a');
				
				node=st[node].next[i+'a'];
				cnt+=dp[node];
				break;
			}
		}
		
	}
	
	cout<<fin;
	return 0;
}