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


const int N=1000005;
int p[N],cur[N],n;
vector<pii> ans;

#define add(x,y) ans.pb(mp(x,y))

inline void LL(int x,int y){
	add(x,n);
	add(n,y);
	add(x,n);
}
inline void RR(int x,int y){
	add(x,1);
	add(1,y);
	add(x,1);
}
inline void LR(int x,int y){
	if(x==1||y==n)add(x,y);
	else{
		add(x,n);
		add(n,1);
		add(1,y);
		add(1,n);
		add(n,x);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i]);
		cur[p[i]]=i;
	}

	rep(i,1,n)
		if(p[i]!=i){
			int x=i,y=cur[i];
			if(x>y)swap(x,y);
			if(x<=n/2&&y<=n/2)LL(x,y);
			else if(x<=n/2&&y>n/2)LR(x,y);
			else RR(x,y);
			swap(cur[p[x]],cur[p[y]]);
			swap(p[x],p[y]);
		}

	cout<<ans.size()<<endl;
	for(auto x:ans)
		printf("%d %d\n",x.fi,x.se);

	return 0;
}