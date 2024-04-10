#pragma warning(disable:4786)//  
#pragma comment(linker, "/STACK:102400000,102400000")// 
#include <vector>  
#include <list>  
#include <map>  
#include <set>  
#include <deque>  
#include <queue>  
#include <stack>  
#include <bitset>   
#include <algorithm>  
#include <functional>  
#include <numeric>  
#include <utility>  
#include <complex>  
#include <sstream>  
#include <iostream>  
#include <iomanip>  
#include <cstdio>  
#include <cmath>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <cassert>  
using namespace std;  
#define lson 2*i    
#define rson 2*i+1    
#define LS l,mid,lson    
#define RS mid+1,r,rson    
#define UP(i,x,y) for(i=x;i<=y;i++)    
#define DOWN(i,x,y) for(i=x;i>=y;i--)    
#define MEM(a,x) memset(a,x,sizeof(a))    
#define W(a) while(a)    
#define gcd(a,b) __gcd(a,b)       
#define N 1000005    
#define MOD 1000000007    
#define INF 0x3f3f3f3f    
#define EXP 1e-8    
#define lowbit(x) (x&-x) 
typedef long long LL;
const int NNN=1000000009;  
const LL modd = 1e9 + 7;  
const double PI = acos(-1.0);  
const double EE = exp(1);  
const double EPS=1e-8;   
inline int read(){
	char ch=getchar();int rre=0;
	while (ch<'0'||ch>'9')ch = getchar();
	while (ch>='0'&&ch<='9')rre = rre*10+ch-'0',ch = getchar();
	return rre;
} 
inline LL readLL(){
	char chLL = getchar();LL rreLL=0LL;
	while (chLL<'0'||chLL>'9')chLL = getchar();
	while (chLL>='0'&&chLL<='9')rreLL = 10*rreLL+chLL-'0',chLL = getchar();
	return rreLL;
}
const int MAX = 3e5+100;
struct Node{
	Node* nxt[2];
	int deep;
	bool full;
};
Node* create(int dep){
	Node* n = (Node*)(malloc(sizeof (Node)));
	memset(n->nxt,0,sizeof(n->nxt));
	n->deep = dep;
	n->full = false;
	return n;
}
Node* root = create(-1);
void init(Node* nod){
	if (nod->deep==19){
		return;
	}
	nod->nxt[0] = create(nod->deep+1);
	init(nod->nxt[0]);
	nod->nxt[1] = create(nod->deep+1);
	init(nod->nxt[1]);
}
void insert(int x){
	Node* nod = root;
	for (int i=19;i>=0;i--){
		int id = (x&(1<<i))?1:0;
		nod = nod->nxt[id];
	}
	nod->full = true;
}
void build(Node* nod){
	if (nod->deep==19){
		return;
	}
	build(nod->nxt[0]);
	build(nod->nxt[1]);
	nod->full = nod->nxt[0]->full&nod->nxt[1]->full;
}
int query(int x){
	Node* nod = root;
	int res =0;
	for (int i=19;i>=0;i--){
		int id = (x&(1<<i))?1:0;
		if (nod->nxt[id]->full){
			nod = nod->nxt[!id];
			res+=(1<<i);
		}else{
			nod=nod->nxt[id];
		}
	}
	
	return res;
}
int m,n;
int main(){
	scanf("%d%d",&n,&m);
	init(root);
	for (int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		insert(temp);
	}
	build(root);
//	cout<<"YES"<<endl;
	int K =0;
	while (m--){
		int temp;
		scanf("%d",&temp);
		K^=temp;
		printf("%d\n",query(K));
	}
	return 0;
}