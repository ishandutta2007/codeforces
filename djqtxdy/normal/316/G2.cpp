#include<cmath>
#include<math.h>
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
#include<ctime>
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
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<tr1\unordered_map>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
//orz tjw
//orz yjz
//author: FST_master ST_master T_master _master master aster ster ter er r
using namespace std;
using namespace tr1;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=50005;
struct node{
	LL pp;
	int val;
	node* nxt;
	node(){
		pp=0,val=0,nxt=NULL;
	}
};
node* MAP[12][1000000];
void add(int x,LL y){
	int yy=y%926817;if (yy<0) yy+=926817;
	node* tmp=MAP[x][yy];
	if (!tmp){
		MAP[x][yy]=new node();
		MAP[x][yy]->pp=y;MAP[x][yy]->val++;
		return;
	}
	while (tmp && tmp->pp!=y){
		tmp=tmp->nxt;
	}
	if (tmp){
		tmp->pp=y;
		tmp->val++;
	}
	else{
		tmp=MAP[x][yy];
		while (1){
			if (!tmp->nxt){
				tmp->nxt=new node();
				tmp->nxt->pp=y;
				tmp->nxt->val++;
				break;
			}
			tmp=tmp->nxt;
		}
	}
}
int gt(int x,LL y){
	int yy=y%926817;if (yy<0) yy+=926817;
	node* tmp=MAP[x][yy];
	while (tmp && tmp->pp!=y){
		tmp=tmp->nxt;
	}
	if (!tmp) return 0;
	return tmp->val;
}
LL ha(LL x,LL y){
    return x*(LL)1e9+y;
}
char ch[Maxn];
int ub[Maxn],lb[Maxn];
const long long mul=20160116;
const LL mul2=20160110;
const long long mod=1e9+9;
const LL mod2=1e9+7;
int main(){
	scanf("%s",ch);
	string t=(string)ch;
	for (int i=0;i<t.size();i++){
		LL nh=0,nh2=0;
		for (int j=i;j<t.size();j++){
			nh=nh*mul+t[j];
			nh2=nh2*mul2+t[j];
			nh%=mod;nh2%=mod2;
			add(0,ha(nh,nh2));
		}
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",ch);
		string tt=(string)ch;
		for (int j=0;j<tt.size();j++){
			LL nh=0,nh2=0;
			for (int k=j;k<tt.size();k++){
				nh=nh*mul+tt[k];
				nh2=nh2*mul2+tt[k];
				nh%=mod;nh2%=mod2;
				add(i+1,ha(nh,nh2));
			}
		}
		//cerr<<i<<endl;
		scanf("%d %d",&lb[i+1],&ub[i+1]);
	}
	int ans=0;
	/*
	for (unordered_map<LL,int>::iterator it=use[0].begin();it!=use[0].end();it++){
		LL v=it->first;
		bool flag=true;
		for (int i=1;i<=n;i++){
			int tm=use[i][v];
			if (lb[i]>tm || ub[i]<tm) flag=false;
		}
		if (flag) ans++;
	}*/
	//cerr<<123<<endl;
	for (int i=0;i<926817;i++){
		node* j=MAP[0][i];
		//cerr<<123<<endl;
		while (j){
			LL v=j->pp;//cerr<<v<<endl;
			bool flag=true;
			for (int k=1;k<=n;k++){
				int tm=gt(k,v);
				if (lb[k]>tm || ub[k]<tm) flag=false;
			}
			if (flag) ans++;
			j=j->nxt;
		}
	}
	printf("%d\n",ans);
}
/*
oaoaa
1
oaooaoooooaaaaaaaoooaao 2 18
*/