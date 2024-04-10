#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
multiset<int> fr,s;
int p[N],c[N],n;

int rmain(){
	read(n);
	s.clear();
	fr.clear();
	rep(i,1,n){
		read(p[i]);
		s.insert(0);
		fr.insert(i);
		c[i]=0;
	}
	rep(i,1,n){
		int mx=*s.rbegin();
		if(c[p[i]]!=mx) return 0;
		s.erase(s.find(c[p[i]]));
		fr.erase(p[i]);
		auto it=fr.upper_bound(p[i]);
		if(it==fr.end()) continue;
		int nxt=*it;
		s.erase(s.find(c[nxt]));
		c[nxt]+=c[p[i]]+1;
		s.insert(c[nxt]);
	}
	return 1;
}

int main(){
	int T; read(T);
	while(T--) puts(rmain()?"Yes":"No");

	return 0;
}