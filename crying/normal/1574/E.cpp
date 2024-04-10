#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e6+10,mod=998244353;
ll n,m,k,x,y,op;
ll ans1,ans2,div2;
int limr[MAXN][2],limc[MAXN][2];
int cntL,cntR,cntr[MAXN],cntc[MAXN]; 
int rcnt1,rcnt2,rcnt0,ccnt1,ccnt2,ccnt0;
map<pi,int>color; 
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
void remove(int x,int y){
	//
	if(color[mp(x,y)]==-1){
		//0
		if(even(y)){
			limr[x][0]--;
			if(limr[x][0]==0){
				if(limr[x][1]==0){
					rcnt1--;rcnt0++;
				}else{
					rcnt2--;rcnt0++;
				}
			}
		}else{
			limr[x][1]--;
			if(limr[x][1]==0){
				if(limr[x][0]==0){
					rcnt1--;rcnt0++;
				}else{
					rcnt2--;rcnt0++;
				}
			}
		}
	}else if(color[mp(x,y)]==1){
		//1
		if(odd(y)){
			limr[x][0]--;
			if(limr[x][0]==0){
				if(limr[x][1]==0){
					rcnt1--;rcnt0++;
				}else{
					rcnt2--;rcnt0++;
				}
			}
		}else{
			limr[x][1]--;
			if(limr[x][1]==0){
				if(limr[x][0]==0){
					rcnt1--;rcnt0++;
				}else{
					rcnt2--;rcnt0++;
				}
			}
		}
	}
	//
	if(color[mp(x,y)]==-1){
		//0
		if(even(x)){
			limc[y][0]--;
			if(limc[y][0]==0){
				if(limc[y][1]==0){
					ccnt1--;ccnt0++;
				}else{
					ccnt2--;ccnt0++;
				}
			}
		}else{
			limc[y][1]--;
			if(limc[y][1]==0){
				if(limc[y][0]==0){
					ccnt1--;ccnt0++;
				}else{
					ccnt2--;ccnt0++;
				}
			}
		}
	}else if(color[mp(x,y)]==1){
		//1
		if(odd(x)){
			limc[y][0]--;
			if(limc[y][0]==0){
				if(limc[y][1]==0){
					ccnt1--;ccnt0++;
				}else{
					ccnt2--;ccnt0++;
				}
			}
		}else{
			limc[y][1]--;
			if(limc[y][1]==0){
				if(limc[y][0]==0){
					ccnt1--;ccnt0++;
				}else{
					ccnt2--;ccnt0++;
				}
			}
		}
	}
	//
	if(color[mp(x,y)]==-1){
		if(even((x+y))){
			cntL--;
		}else{
			cntR--;
		}
	}else if(color[mp(x,y)]==1){
		if(odd((x+y))){
			cntL--;
		}else{
			cntR--;
		}
	}
	color[mp(x,y)]=0;
}
void coverzero(int x,int y){
	remove(x,y);
	// 
	if(even(y)){
		limr[x][0]++;
		if(limr[x][0]==1){
			if(limr[x][1]==0){
				rcnt1++;rcnt0--;
			}else{
				rcnt2++;rcnt0--;
			}
		}
	}else{
		limr[x][1]++;
		if(limr[x][1]==1){
			if(limr[x][0]==0){
				rcnt1++;rcnt0--;
			}else{
				rcnt2++;rcnt0--;
			}
		}
	}
	//
	if(even(x)){
			limc[y][0]++;
			if(limc[y][0]==1){
				if(limc[y][1]==0){
					ccnt1++;ccnt0--;
				}else{
					ccnt2++;ccnt0--;
				}
			}
		}else{
			limc[y][1]++; 
			if(limc[y][1]==1){
				if(limc[y][0]==0){
					ccnt1++;ccnt0--;
				}else{
					ccnt2++;ccnt0--;
				}
			}
	}
	//
	if(even((x+y))){
		cntL++;
	}else{
		cntR++;
	}
	color[mp(x,y)]=-1;
} 
void coverone(int x,int y){
	remove(x,y);

	// 
	if(odd(y)){
		limr[x][0]++;
		if(limr[x][0]==1){
			if(limr[x][1]==0){
				rcnt1++;rcnt0--;
			}else{
				rcnt2++;rcnt0--;
			}
		}
	}else{
		limr[x][1]++;
		if(limr[x][1]==1){
			if(limr[x][0]==0){
				rcnt1++;rcnt0--;
			}else{
				rcnt2++;rcnt0--;
			}
		}
	}
	//
	if(odd(x)){
			limc[y][0]++;
			if(limc[y][0]==1){
				if(limc[y][1]==0){
					ccnt1++;ccnt0--;
				}else{
					ccnt2++;ccnt0--;
				}
			}
		}else{
			limc[y][1]++; 
			if(limc[y][1]==1){
				if(limc[y][0]==0){
					ccnt1++;ccnt0--;
				}else{
					ccnt2++;ccnt0--;
				}
			}
	}
	//
	if(odd((x+y))){
		cntL++;
	}else{
		cntR++;
	}
	color[mp(x,y)]=1;
}
void calc(){
	ll ret=0;
	if(!rcnt2){
		ret+=power(2,rcnt0);
	}
	if(!ccnt2){
		ret+=power(2,ccnt0);
	}
//	printf("%lld %lld %lld %lld\n",rcnt0,ccnt0,cntL,cntR);
	if(cntL==0)ret--;
	if(cntR==0)ret--;
	printf("%lld\n",ret%mod);
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k); 
	rcnt0=n;
	ccnt0=m;
	ans1=power(2,n);ans2=power(2,m);
	rep(i,1,k){
		scanf("%lld%lld%lld",&x,&y,&op);
		if(op==-1){
			remove(x,y);
		}else if(op==0){
			coverzero(x,y);
		}else{
			coverone(x,y);
		}
		calc();
	}

	return 0;
}
/*
2 2 1
1 1 1
*/