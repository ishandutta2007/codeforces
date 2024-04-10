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
const int MAXN=2e5+10;
struct Node{
	int a,idx;
	bool operator<(const Node& n2)const{
		return a<n2.a;
	}
};
priority_queue<Node>q;
int T,n,a[MAXN];
vector<pi>ret;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		while(q.size())q.pop();
		ret.clear();
		rep(i,1,n){
			scanf("%d",&a[i]);
			q.push((Node){a[i],i});
		}
		while(q.size()>=2){
			Node n1=q.top();q.pop();
			Node n2=q.top();q.pop();
			if(n1.a==0 || n2.a==0)break;
			ret.pb(mp(n1.idx,n2.idx));
			n1.a--;n2.a--;
			q.push(n1);q.push(n2);
		}
		int sz=ret.size();
		printf("%d\n",sz);
		for(auto info:ret)printf("%d %d\n",info.fr,info.se);
	}

	return 0;
}