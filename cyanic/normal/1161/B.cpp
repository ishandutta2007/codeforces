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

const int N=100005;
struct piihash{
	ll operator () (pii owo) const {
		return (ll)owo.fi*N+owo.se;
	}
};
unordered_set<pii,piihash> s;
int f[N],n,m;

int chk(int x){
	for(auto p:s){
		int u=(p.fi+x)%n;
		int v=(p.se+x)%n;
		if(u>v)swap(u,v);
		if(s.find(mp(u,v))==s.end())return 0;
	}
	return 1;
}

int main(){
	rep(i,2,N-1)if(!f[i])
		for(int j=2;j*i<N;j++)f[i*j]=1;
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		if((--u)>(--v))swap(u,v);
		s.insert(mp(u,v));
	}
	rep(i,2,n)if(!f[i]&&n%i==0)
		if(chk(n/i))puts("Yes"),exit(0);
	puts("No");
	return 0;
}