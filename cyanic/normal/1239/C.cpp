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
typedef pair<ll,int> pli;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
set<pli> undo,order;	// 	
set<int> wait,que;		// 
int t[N],n,p;
ll ans[N],T;

void Undo(){
	int x=undo.begin()->se;
	T=undo.begin()->fi;
	undo.erase(undo.begin());
	wait.insert(x);
}

void Wait(){
	if(wait.size()&&(!que.size()||*wait.begin()<*que.begin())){
		int x=*wait.begin();
		wait.erase(wait.begin());
		que.insert(x);
		order.insert(mp(T,x));
	}
}

int main(){
	read(n),read(p);
	rep(i,1,n){
		read(t[i]);
		undo.insert(mp(t[i],i));
	}
	while(undo.size()||wait.size()||que.size()){
		Wait();
		if(undo.size()&&(!order.size()||
						undo.begin()->fi<=order.begin()->fi)) 
		 	Undo();
		else{
			int x=order.begin()->se;
			order.erase(order.begin());
			ans[x]=T+p;
			Wait();
			while(undo.size()&&undo.begin()->fi<=ans[x])
				Undo(),Wait();
			que.erase(x);
			T=ans[x];
			Wait();
		}
	}
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}