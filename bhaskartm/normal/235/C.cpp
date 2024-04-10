#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
string stt;

struct state{
	int len, link;
	map<char, int>next;
};

const int N=1e6+5;
state st[N*2];
int dp[N*2];
bool vis[2*N];
bool che[2*N];
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

int mini(int v){
	return (st[st[v].link].len)+1;
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>stt;


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
	
	int n;
	cin>>n;
	while(n--){
		string tt;
	
		cin>>tt;
		int m=tt.size();
		tt+=tt;
		tt.pop_back();
		int v=0;
		int l=0;
		int ans=0;
		vector<int>don;
		for(int i=0; i<tt.size(); i++){
			while((v && !st[v].next.count(tt[i]))){
				v=st[v].link;
				l=st[v].len;
			}
			if(st[v].next.count(tt[i])){
				v=st[v].next[tt[i]];
				l++;
			}
			if(mini(v)>m){
				v=st[v].link;
				l=st[v].len;
			}
			if(l>=m){
				if(!vis[v]){
					ans+=dp[v];
					
					vis[v]=1;
					
					don.pb(v);
				}
			}
			
		}
		
		cout<<ans<<endl;
		for(auto u:don){
			vis[u]=0;
		}
	}
	
	return 0;
}