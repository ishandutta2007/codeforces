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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int x[N],y[N],Q,op,cnt,res;
map<pii,int> ans,id,owo;
map<ll,int> cur;
set<int> s[N];

void add(int x,int y,int op){
	int g=__gcd(x,y);
	ans[mp(x/g,y/g)]+=op;
}

int main(){
	read(Q);
	rep(i,1,Q){
		read(op);
		read(x[i]),read(y[i]);
		int g=__gcd(x[i],y[i]);
		if(op==1||op==2){
			ll t=(ll)x[i]*x[i]+(ll)y[i]*y[i];
			int k=cur[t];
			if(!k) cur[t]=k=++cnt;
			if(op==1){
				for(auto j:s[k]) add(x[i]+x[j],y[i]+y[j],1);
				s[k].insert(i),id[mp(x[i],y[i])]=i,res++;
				owo[mp(x[i]/g,y[i]/g)]++;
			}
			else{
				s[k].erase(id[mp(x[i],y[i])]),res--;
				for(auto j:s[k]) add(x[i]+x[j],y[i]+y[j],-1);
				owo[mp(x[i]/g,y[i]/g)]--;
			}
		}
		else{
			printf("%d\n",(res-ans[mp(x[i]/g,y[i]/g)])*2
						-res-owo[mp(x[i]/g,y[i]/g)]);
		}
	}
	return 0;
}