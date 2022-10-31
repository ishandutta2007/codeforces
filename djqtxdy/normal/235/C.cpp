/*
problem:
verdict:
author:FST_master
*/
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
#define ll   long long
#define ull unsigned long long
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
using namespace std;
const int Maxn=1e6+5;
int cur;
struct node{
	node* nxt[26],*par;
	int len;int siz;int id;
	node(int val){
		id=++cur;
		len=val;
		siz=0;
		memset(nxt,0,sizeof(nxt));
		par=NULL;
	}
};
node* nd[Maxn*4];
struct SAM{
	node* root,*last;
	vector<node*> nodes;
	vector<vector<int> > G;
	SAM(){
		G.clear();
		nodes.clear();
		root=last=new node (0);
		nodes.pb(root);
	}
	void build_tree(){
		G.resize(nodes.back()->id+1);
		for (int i=0;i<nodes.size();i++){
			nd[nodes[i]->id]=nodes[i];
			if (nodes[i]->par){
				G[nodes[i]->par->id].pb(nodes[i]->id);
				//cerr<<"ADD_EDGE"<<' '<<nodes[i]->par->id<<' '<<nodes[i]->id<<endl;
			}
		}
		dfs(root->id);
	}
	void dfs(int id){
		for (int i=0;i<G[id].size();i++){
			dfs(G[id][i]);
			nd[id]->siz+=nd[G[id][i]]->siz;
		}
		//cout<<id<<' '<<nd[id]->siz<<endl;
	}
	void add(int c){
		node *p=new node(last->len+1);
		p->siz=1;
		nodes.push_back(p);
		node *tmp=last;
		while (tmp && !tmp->nxt[c]){
			tmp->nxt[c]=p;
			tmp=tmp->par;
		}
		if (!tmp){
			p->par=root;
		}
		else{
			node *q=tmp->nxt[c];
			if (q->len==tmp->len+1){
				p->par=q;
			}
			else{
				node *nq=new node(tmp->len+1);
				nodes.push_back(nq);
				for (int i=0;i<26;i++){
					nq->nxt[i]=q->nxt[i];
				}
				nq->par=q->par;
				q->par=nq;
				p->par=nq;
				while (tmp && tmp->nxt[c]==q){
					tmp->nxt[c]=nq;tmp=tmp->par;
				}
			}
		}
		last=p;
	}
	void build(string s){
		for (int i=0;i<s.length();i++){
			add(s[i]-'a');
		}
	}
};
char tt[Maxn];
string s;
vector<pair<node*,int> > use;
int main(){
	scanf("%s",tt);
	s=(string)tt;
	int n;
	scanf("%d",&n);
	SAM sam;
	sam.build(s);
	sam.build_tree();
	for (int i=1;i<=n;i++){
		scanf("%s",tt);
		string dd=(string)tt;
		int bb=dd.size();
		dd=dd+dd;
		int ans=0;
		node* now=sam.root;
		int curlen=0;
		use.clear();
		for (int j=0;j<dd.size();j++){
			if (now->nxt[dd[j]-'a']==NULL){
				while (now && now->nxt[dd[j]-'a']==NULL){
					now=now->par;
				}
				if (!now){
					now=sam.root;
					curlen=0;
				}
				else{
					curlen=now->len+1;
					now=now->nxt[dd[j]-'a'];
				}
			}
			else{
				now=now->nxt[dd[j]-'a'];
				curlen++;
			}	
			while (now){
				if (!now->par){
					//cerr<<123;
					break;
				}
				if (now->par->len<bb) break;
				now=now->par;
			}
			if (curlen>=bb){
				ans+=now->siz;
				use.pb(mp(now,now->siz));
				now->siz=0;
			}
		}
		for (int j=0;j<use.size();j++){
			use[j].first->siz+=use[j].second;
		}
		printf("%d\n",ans);
	}
	End;
}