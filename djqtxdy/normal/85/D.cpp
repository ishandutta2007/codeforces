#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
// cf IO: I64d
// atcoder IO: 
const int Maxn=100005;
int tot;
struct node{
	LL val,fix;
	LL sum[5];
	int siz;
	node *l,*r;
	node(){
		l=NULL,r=NULL;
		memset(sum,0,sizeof(sum));
		val=0,fix=0;
	}
	int lsize(){
		return (l)?l->siz:0;
	}
	int rsize(){
		return (r)?r->siz:0;
	}
};
node *root;
void Update(node* p){
	if (!p) return;
	p->siz=p->lsize()+p->rsize()+1;
	for (int i=0;i<5;i++) p->sum[i]=0;
	int tmp=0;
	if (p->l){
		for (int i=0;i<5;i++) p->sum[i]+=p->l->sum[i];
		tmp=p->lsize()%5;
	}
	p->sum[tmp]+=p->val;
	tmp++;
	tmp%=5;
	if (p->r){
		for (int i=0;i<5;i++) p->sum[(i+tmp)%5]+=p->r->sum[i];
	}
}
node Node[Maxn];
void treap_merge(node* l,node* r,node *&res){
	if (!l || !r){
		if (l) res=l;
		else res=r;
	}
	else if (l->fix>r->fix){
		treap_merge(l,r->l,r->l);
		res=r;
	}
	else{
		treap_merge(l->r,r,l->r);
		res=l;
	}
	Update(res);
	return;
}
void treap_split(node* p,node* &l, node* &r,int k){
	if (!p){
		l=NULL,r=NULL;
		return;
	}
	else if (p->val>k){
		treap_split(p->l,l,p->l,k);
		r=p;
	}
	else{
		treap_split(p->r,p->r,r,k);
		l=p;
	}
	Update(p);
	//Update(l);
	//Update(r);
}
void treap_ins(int val){
	node* l,* r,* k;
	treap_split(root,l,r,val);
	k=&Node[tot++];
	k->fix=rand();
	k->val=val;
	Update(k);
	//if (l)cout<<l->siz<<endl;
	treap_merge(l,k,root);
	//cout<<root->siz<<endl;
	treap_merge(root,r,root);
	
}
void treap_del(node* &p,int val){
	if (p->val==val){
		treap_merge(p->l,p->r,p);
	}
	else if (p->val<val){
		treap_del(p->r,val);
	}
	else{
		treap_del(p->l,val);
	}
	Update(p);
}
char op[5];

int main(){
	srand(20160116);
	root=NULL;
	int n;
	scanf("%d\n",&n);
	for (int i=0;i<n;i++){
		scanf("%s",op);
	//	if (root)cout<<"siz"<<' '<<root->siz<<endl;
		if (op[0]=='a'){
			int x;
			scanf("%d\n",&x);
			treap_ins(x);
		}
		else if (op[0]=='d'){
			int x;
			scanf("%d\n",&x);
			treap_del(root,x);
		}
		else{
			if (!root) printf("0\n");
			else printf("%I64d\n",root->sum[2]);
		}
		
	}
	return 0;
}
/*
24
add 1
sum
add 2
sum
add 7
sum
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum
*/