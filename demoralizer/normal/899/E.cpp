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

struct seg
{
	int l,r,length,val;
	bool operator< (const seg& other)const{
		return (length == other.length) ? l<other.l : length>other.length;
	}
} l[N],r[N];

set<seg> s;
int a[N];
void solve(){
	int n;
	cin>>n;
	
	l[0].val = r[0].val=-1;
	l[n+1].val = r[n+1].val=-2;
	
	seg cur;cur.val=-1;
	
	rep(i,1,n+1){
		cin>>a[i];
		if(cur.val == a[i]){
			cur.length++;
			cur.r=i;
		}
		else{
			if(i!=1){
				l[cur.l]=cur;
				r[cur.r]=cur;
				s.insert(cur);
			}
			cur.val=a[i];
			cur.l=i;
			cur.r=i;
			cur.length=1;
		}
	}
	s.insert(cur);
	l[cur.l]=cur;
	r[cur.r]=cur;
	
	// rep(i,1,n+1){
	// 	cout<<l[i].l<<" "<<l[i].r<<" "<<l[i].val<<" "<<l[i].length<<"\n";
	// 	cout<<r[i].l<<" "<<r[i].r<<" "<<r[i].val<<" "<<r[i].length<<"\n";
	// }
	
	int ans=0;
	while(!s.empty()){
		ans++;
		auto x=*s.begin();
		s.erase(s.begin());
		if(r[x.l-1].val == l[x.r+1].val){
			s.erase(r[x.l-1]);
			s.erase(l[x.r+1]);
			cur.val=r[x.l-1].val;
			cur.l=r[x.l-1].l;
			cur.r=l[x.r+1].r;
			cur.length=r[x.l-1].length+l[x.r+1].length;
			l[cur.l]=cur;
			r[cur.r]=cur;
			s.insert(cur);
		}
		else{
			cur=r[x.l-1];
			s.erase(cur);
			cur.r=x.r;
			l[cur.l]=cur;
			r[cur.r]=cur;
			if(cur.val==-1) continue;
			s.insert(cur);
		}
	}
	cout<<ans;
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