#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=3005;
int L[N],R[N],r,c,n,K,x,y,now,cnt;
multiset<int> s;
vi pos[N];
ll ans,acc;

int main(){
	read(r),read(c);
	read(n),read(K);
	rep(i,1,n){
		read(x),read(y);
		pos[x].pb(y);
	}
	per(i,r,1){
		if(pos[i].empty()){
			acc+=(ll)c*(c+1)/2;
			ans+=acc;
			continue;
		}
		now=(ll)c*(c+1)/2,acc=0;
		s.clear();
		rep(j,i,r){
			for(auto p:pos[j]){
				auto it=s.insert(p),L=it,R=it; int cnt=1;
				while(L!=s.begin()&&cnt<K)L--,++cnt;
				while(R!=s.end()&&cnt<K)R++,++cnt;
				while(R!=s.end()){
					auto t=L;
					int l=(L==s.begin()?*L:*L-*(--t));
					t=R,t++;
					int r=(t==s.end()?c+1-*R:*t-*R);
					now-=l*r;
					if(L==it)break;
					++L,++R;
				}
			}
			acc+=now;
		}
		ans+=acc;
	}
	ans=(ll)r*(r+1)*c*(c+1)/4-ans;
	cout<<ans<<endl;
	return 0;
}