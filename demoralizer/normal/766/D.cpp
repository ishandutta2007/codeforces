#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

int parent[N],size[N];
int findParent(int i)
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}
void unionNodes(int a,int b)
{
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

map<string, int> mp;

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	cleardsu(2*n);
	
	rep(i,0,n){
		string s;
		cin>>s;
		mp[s]=2*i;
	}
	
	rep(i,0,m){
		int t;
		string a,b;
		cin>>t>>a>>b;
		int x=mp[a],y=mp[b];
		if(t==1){
			if(findParent(x) == findParent(y^1)){
				cout<<"NO\n";
				continue;
			}
			unionNodes(x,y);
			unionNodes(x^1,y^1);
		}
		else{
			if(findParent(x) == findParent(y)){
				cout<<"NO\n";
				continue;
			}
			unionNodes(x,y^1);
			unionNodes(x^1,y);
		}
		cout<<"YES\n";
	}
	
	rep(i,0,q){
		string a,b;
		cin>>a>>b;
		int x=mp[a],y=mp[b];
		if(findParent(x) == findParent(y)){
			cout<<"1\n";
		}
		else if(findParent(x) == findParent(y^1)){
			cout<<"2\n";
		}
		else{
			cout<<"3\n";
		}
	}
	
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}