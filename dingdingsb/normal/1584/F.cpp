//

// Problem: D. Strange LCS
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.ml/contest/1588/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=11;
int t,n;char s[150];
int nxt[N][150][150];
map<vector<int>,pair<int,string>>dp;
pair<int,string>dfs(vector<int>now){
	if(dp.count(now))return dp[now];
	pair<int,string>res;
	for(char i='a';i<='z';i++){
		bool fl=1;
		vector<int>tmp;
		for(int j=1;j<=n;j++){
			if(nxt[j][now[j-1]][i]==-1){fl=0;break;}
			else tmp.pb(nxt[j][now[j-1]][i]);
		}
		if(fl){
			auto kk=dfs(tmp);
			chkmx(res,mp(kk.fi+1,i+kk.se));
		}
	}
	for(char i='A';i<='Z';i++){
		bool fl=1;
		vector<int>tmp;
		for(int j=1;j<=n;j++){
			if(nxt[j][now[j-1]][i]==-1){fl=0;break;}
			else tmp.pb(nxt[j][now[j-1]][i]);
		}
		if(fl){
			auto kk=dfs(tmp);
			chkmx(res,mp(kk.fi+1,i+kk.se));
		}
	}
	return dp[now]=res;
}
signed main(){
	read(t);while(t--){
		dp.clear();
		memset(nxt,0xff,sizeof nxt);
		read(n);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);int l=strlen(s+1);
			for(int j=0;j<=l;j++)
				for(int k=l;k>j;k--)
					nxt[i][j][s[k]]=k;
		}
		auto ans=dfs(vector<int>(n,0));
		cout<<ans.first<<endl<<ans.second<<endl;
	}
}