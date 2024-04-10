#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=100005;

string s,t;
int pi[N];

int tr[N][26];

void prefix_function(string s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

vector<vector<int>> dp;

int calc(int x,int z){
	if(x==sz(s))return 0;
	int &ans=dp[x][z];
	if(ans!=-1)return ans;
	ans=0;
	if(s[x]!='?'){
		int tmp=tr[z][s[x]-'a'];
		if(tmp==sz(t)){
			tmp=pi[tmp-1];
			ans=1;
		}
		ans+=calc(x+1,tmp);
		return ans;
	}
	rep(i,0,26){
		int tans=0;
		int tmp=tr[z][i];
		if(tmp==sz(t)){
			tmp=pi[tmp-1];
			tans=1;
		}
		tans+=calc(x+1,tmp);
		ans=max(ans,tans);
	}
	return ans;
}

void solve(){
	cin>>s>>t;
	prefix_function(t);
	if(sz(t)>sz(s)){
		cout<<0;
		return;
	}
	rep(i,0,sz(s)){
		vector<int> v(sz(t),-1);
		dp.pb(v);
	}
	rep(i,0,sz(t)){
		rep(j,0,26){
			char c=j+'a';
			int tmp=i;
			while(tmp>0 && c!=t[tmp])tmp=pi[tmp-1];
			if(c==t[tmp])tmp++;
			tr[i][j]=tmp;
		}
	}
	cout<<calc(0,0);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}