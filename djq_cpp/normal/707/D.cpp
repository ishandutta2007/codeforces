#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
#define V first
#define ST second
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
void getk(int &k){scanf("%d",&k);k--;}
struct STATE{
	int oper,i,j;
	STATE(){oper=0;}
	void get(){scanf("%d%d",&oper,&i);if(oper!=4)i--;;if(oper==1||oper==2)getk(j);}
};
int n,m,q,ans,cur[1005][1005],rev[1005],sum[1005],res[100005];
vector<pair<int,STATE> > nxt[100005];
int setb(int i,int j,int v,bool &ifc){
	int ra=ans;
	ans=ans-(cur[i][j]^rev[i])+v;
	ifc=(ra!=ans);
	sum[i]=sum[i]-(cur[i][j]^rev[i])+v;
	cur[i][j]=v^rev[i];
}
void revb(int i){
	rev[i]^=1;
	ans-=sum[i];
	sum[i]=m-sum[i];
	ans+=sum[i];
}
void doit(STATE &st,bool &ifc){
	if(st.oper==1)setb(st.i,st.j,1,ifc);
	if(st.oper==2)setb(st.i,st.j,0,ifc);
	if(st.oper==3)revb(st.i);
}
void back(STATE &st,bool ifc){
	if(ifc){
		if(st.oper==1)setb(st.i,st.j,0,ifc);
		if(st.oper==2)setb(st.i,st.j,1,ifc);
	}
	if(st.oper==3)revb(st.i);
}
void init(){
	rep1(k,q){
		STATE now;
		now.get();
		int id=k-1;
		if(now.oper==4)id=now.i;
		nxt[id].push_back(MP(k,now));
	}
}
void dfs(int id,STATE now){
	bool c=false;
	doit(now,c);
	res[id]=ans;
	rep(k,nxt[id].size())dfs(nxt[id][k].V,nxt[id][k].ST);
	back(now,c);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	init();
	dfs(0,STATE());
	rep1(k,q)printf("%d\n",res[k]);
	return 0;
}