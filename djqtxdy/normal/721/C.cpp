#include<cmath>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL   long long
#define ULL unsigned long long
#define MP make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define INF 2147483647
#define ull unsigned long long
#define VI vector < int >
#define vpii vector < pii >
#define PQ priority_queue
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
using namespace std;
const int Maxn=5005;
bool vis[Maxn][Maxn];
pii p[Maxn][Maxn];
vector<pair<int,int> > G[Maxn];
int n,m,T;
struct s{
	int t;
	int x,y;
	int px,py;
	bool operator<(const s &a) const{
		return this->t<a.t;
	}
	void print(){
		printf("%d %d %d %d %d\n",this->t,this->x,this->y,this->px,this->py);
	}
};
int main(){
	scanf("%d %d %d",&n,&m,&T);
	for (int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
	}
	for (int i=0;i<Maxn;i++){
		for (int j=0;j<Maxn;j++){
			p[i][j]=make_pair(-1,-1);
		}
	}
	priority_queue<s> Q;
	s buff;
	buff.x=1,buff.y=0;
	buff.px=-1,buff.py=-1;
	buff.t=0;
	Q.push(buff);
	while (!Q.empty()){
		
		s X=Q.top();
		X.t=-X.t;
		Q.pop();
		if (vis[X.x][X.y] || X.t>T) continue;
		//X.print();
		vis[X.x][X.y]=true;
		p[X.x][X.y]=make_pair(X.px,X.py);
		for (int i=0;i<G[X.x].size();i++){
			int u=G[X.x][i].first;
			int dist=X.t+G[X.x][i].second;
			s buff;
			buff.x=u,buff.t=-dist;
			buff.y=X.y+1;
			buff.px=X.x;
			buff.py=X.y;
			Q.push(buff);
		}
	}
	int j;
	for (int i=1;i<=n;i++){
		if (vis[n][i]){
			j=i;
		}
	}
	cout<<j+1<<endl;
	int nx=n,ny=j;
	vector<int> ans;
	while (nx!=-1){
		ans.push_back(nx);
		pair<int,int> buff=p[nx][ny];
		nx=buff.first,ny=buff.second;
	}
	reverse(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}