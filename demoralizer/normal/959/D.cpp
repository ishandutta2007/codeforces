#include <bits/stdc++.h>
using namespace std;
// #define int               long long
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
const int32_t M=1e6+4e5;
const int32_t MM=998244353;

const int N=0;

vector<int> p[M],pr;
void process_seive(int n=M){
    rep(i,2,n+1){
        if(sz(p[i])) continue;
        pr.pb(i);
        for(int j=i;j<=n;j+=i){
            p[j].pb(i);
        }
    }
}

int used[100005];

void solve(){
	set<int> s(all(pr));
	bool diff=0;
	int n;
	cin>>n;
	rep(i,0,n){
		//cout<<"\n"<<i<<" "<<used[2]<<"\n";
		if(diff){
			cout<<*s.begin()<<" ";
			s.erase(*s.begin());
			continue;
		}
		int x;
		cin>>x;
		int y=x-1;
		bool flag=1;
		do{
			y++;
			flag=0;
			for(int x:p[y])if(used[x]){
				flag=1;
				break;
			}
		}while(flag);
		if(y!=x)diff=1;
		cout<<y<<" ";
		for(int x:p[y]){
			// cout<<"\n"<<y<<" "<<x<<"\n";
			used[x]=1;
			s.erase(x);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
		process_seive(M-2);
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}