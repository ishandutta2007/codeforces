/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int QU=100000,LOG_X=30;
int qu;
struct trie{
	int sz;
	struct node{int son[2],num;}nd[QU*(LOG_X+1)+2];
	#define son(p) nd[p].son
	#define num(p) nd[p].num
	int nwnd(){return nd[++sz]=(node){{0,0},0},sz;}
	void init(){sz=0;nwnd();}
	void insert(int v){
		int p=1;
		for(int i=30;~i;i--){
			if(!son(p)[!!(v&1<<i)])son(p)[!!(v&1<<i)]=nwnd();
			p=son(p)[!!(v&1<<i)];
			num(p)++;
		}
	}
	void del(int v){
		int p=1;
		for(int i=30;~i;i--){
			p=son(p)[!!(v&1<<i)];
			num(p)--;
		}
	}
	int lnum(int v1,int v2){
		int p=1,res=0;
		for(int i=30;~i;i--){
			if(v2&1<<i)res+=son(p)[!!(v1&1<<i)]?num(son(p)[!!(v1&1<<i)]):0;
			p=son(p)[v2&1<<i?!(v1&1<<i):!!(v1&1<<i)];
		}
		return res;
	}
}tri;
int main(){
	tri.init();
	cin>>qu;
	while(qu--){
		int tp,x,y;
		cin>>tp>>x;
		if(tp==1)tri.insert(x);
		else if(tp==2)tri.del(x);
		else cin>>y,cout<<tri.lnum(x,y)<<"\n";
	}
	return 0;
}
/*1
5
1 3
1 4
3 6 3
2 4
3 6 3
*/