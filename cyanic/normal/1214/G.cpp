#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
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

const int N=2005;
int c[N],n,m,Q,x,l,r;
bits a[N],p[N];
set<pii> s,t;

void add(int x,int y,int op){
	if((a[x]&a[y])==a[x]) return;
	if(op==1) t.insert(mp(x,y));
	else t.erase(mp(x,y));
}
void ins(int x,int y){
	auto it=s.insert(mp(y,x)).fi;
	add(prev(it)->se,next(it)->se,-1);
	add(prev(it)->se,it->se,1);
	add(it->se,next(it)->se,1);
}
void era(int x,int y){
	auto it=s.find(mp(y,x));
	add(prev(it)->se,next(it)->se,1);
	add(prev(it)->se,it->se,-1);
	add(it->se,next(it)->se,-1);
	s.erase(it);
}

int main(){
	read(n),read(m),read(Q);
	rep(i,1,m) p[i]=p[i-1],p[i].set(i);
	a[n+1]=p[m],s.insert(mp(c[n+1]=m,n+1));
	rep(i,0,n) s.insert(mp(c[i]=0,i));
	for(;Q;Q--){
		read(x),read(l),read(r);
		era(x,c[x]);
		a[x]^=p[r]^p[l-1];
		ins(x,c[x]=a[x].count());
		if(t.empty()){
			puts("-1");
			continue;
		}
		int u=t.begin()->fi,v=t.begin()->se;
		bits tmp=a[u]&a[v];
		int f=(a[u]^tmp)._Find_first();
		int g=(a[v]^tmp)._Find_first();
		if(u>v) swap(u,v);
		if(f>g) swap(f,g);
		printf("%d %d %d %d\n",u,f,v,g);
	}
	return 0;
}