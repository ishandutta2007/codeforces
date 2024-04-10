#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

#define X first
#define Y second
#define rep(i,a,f) for(int i = a;i < f;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef long double ld;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<string, string> PS;
typedef vector<PS> VPS;
typedef pair<ll , ll> Pll;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

ll G[4][4];

ll sqr(ll x){
	return (ll)(x*x);
}

ll dist(Pll a, Pll b){
	return (sqr(a.X-b.X)+sqr(a.Y-b.Y));
}

Pll pun(ll a,ll b,ll c){
	if(a*b*c == 0) return Pll(-1,-1);
	if(a == b && c > a) return Pll(a,c);
	if(b == c && a > b) return Pll(b,a);
	if(c == a && b > c) return Pll(c,b);
	return Pll(-1,-1);
}

bool qua(Pll a,Pll b,Pll c,Pll d){
	return ((pun(dist(a,b),dist(a,c),dist(a,d)) == pun(dist(a,b),dist(b,c),dist(b,d))) &&
	(pun(dist(a,c),dist(b,c),dist(c,d)) == pun(dist(a,b),dist(b,c),dist(b,d))) &&
	(pun(dist(a,c),dist(b,c),dist(c,d)) == pun(dist(a,d),dist(d,c),dist(b,d))) &&
	(pun(dist(a,d),dist(d,c),dist(b,d)) != Pll(-1,-1)));
}

void rotate(int i){
	int x = G[i][0];
	int y = G[i][1];
	G[i][0] = G[i][2]-(y-G[i][3]);
	G[i][1] = G[i][3]+(x-G[i][2]);
}

int f(int k){
	if(k == 4){
		/*
		if(qua(PD(G[0][0],G[0][1]),PD(G[1][0],G[1][1]),PD(G[2][0],G[2][1]),PD(G[3][0],G[3][1]))){
			for(int i = 0;i < 4;++i){
				cout<<G[i][0]<<" "<<G[i][1]<<endl;
			}
		}
		* */
		if(qua(Pll(G[0][0],G[0][1]),Pll(G[1][0],G[1][1]),Pll(G[2][0],G[2][1]),Pll(G[3][0],G[3][1]))) {
			return 0;
			for(int i = 0;i < 4;++i){
				//cout<<G[i][0]<<" "<<G[i][1]<<endl;
			}
		}
		return -1;
	}
	int res = -1;
	//if(k == 3) cout<<G[k][0]<<" "<<G[k][1]<<endl;
	for(int i = 0;i < 4;++i){
		int pos = i+f(k+1);
		if((res == -1 || res > pos) && pos >= i){ 
			res = pos;
			//if(pos==0) cout<<i<<endl;
		 }
		rotate(k);
	}
	//for(int i = 0;i < k;++i) cout<<" ";
	//cout<<"--> "<<k<<"--> "<<res<<endl;
	return res;
}

int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < 4;++j){
			for(int w = 0; w < 4;++w){
				cin>>G[j][w];
			}
		}
		cout<<f(0)<<endl;
	}
	
}
/*
3
-2248 6528 -2144 6181
-2245 6663 -2100 7054
-4378 7068 -4061 7516
-4274 6026 -3918 5721
4942 -6793 5014 -6807
3463 -5170 3112 -5181
2870 -6992 3038 -6567
5688 -4318 5358 -4744
5249 7233 5016 6863
4312 7385 4162 7383
5965 9138 5607 8728
4053 8349 4124 8389
* */