#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn=200005;
char s[maxn];int n;

struct node{
	node *ch[2],*pre;
	int size;
	int value;
	bool flip;
	
	inline int getsize(){
		return this?size:0;
	} 
	
	inline void maintain(){
		size=1;
		size+=ch[0]->getsize()+ch[1]->getsize();
	}
	
	inline void push_down(){
		if (!this) return;
		if (flip){
			flip=0;
			swap(ch[0],ch[1]);
			if (ch[0]) ch[0]->flip^=1;
			if (ch[1]) ch[1]->flip^=1;
		} 
	}
	
	inline void rotate(int d);
};

node pool[maxn*3];
node* poolcount=pool;	
node *root,*root1,*nothing,*zero,*nplus1;
int m,a,b,rightt;

inline void node::rotate(int d){
	node* fa=this->pre;
	fa->push_down();
	this->push_down();
	fa->ch[!d]=this->ch[d];
	if (this->ch[d]) this->ch[d]->pre=fa;
	this->pre=fa->pre;
	if (fa->pre){
		if (fa->pre->ch[0]==fa) 
		   fa->pre->ch[0]=this;
        else
    	   fa->pre->ch[1]=this;
	}
 	this->ch[d]=fa;
	fa->pre=this;
	fa->maintain();
	this->maintain();
	if (fa==root) root=this; 
}

inline node* newnode(node *pre,int v){
	node *x=poolcount++;
	x->size=1;
	x->value=v;
	x->flip=0;
	x->pre=pre;
	x->ch[0]=x->ch[1]=NULL; 
	return x;
}

inline node* build(node* pre,int l,int r){
	if (l>r) return NULL;
	int mid=(l+r)>>1;
	node* x=newnode(pre,mid);
	x->ch[0]=build(x,l,mid-1);
	x->ch[1]=build(x,mid+1,r);
	x->maintain();
	return x;
}

inline void splay(node *x,node *f){
	node *y,*z;
	for (x->push_down();x->pre!=f;){
		y=x->pre;z=y->pre;
		if (z==f){
			if (y->ch[0]==x) x->rotate(1);
			   				 else x->rotate(0);
		} 
		else{
			if (z->ch[0]==y){
				if (y->ch[0]==x) {
					y->rotate(1); x->rotate(1);
				}
				else{
					x->rotate(0); x->rotate(1);
				}
			}
			else{
				if (y->ch[0]==x) {
					x->rotate(1); x->rotate(0);
				}
				else{
					y->rotate(0); x->rotate(0);
				}
			}
		}
	}
}

inline void select(node* f,int k){
	node *cur=root;
	int tmp;
	while (1){
		cur->push_down();
		tmp=cur->ch[0]->getsize()+1;
		if (k==tmp) break;
		if (k<tmp)
		   cur=cur->ch[0];
		else{
			k-=tmp;
			cur=cur->ch[1];
		} 
	}
	splay(cur,f);
}

void print(node* x){
	 x->push_down();
	 if (!x) return;
	 print(x->ch[0]);
	 if (!((x->value==0)||(x->value==n+1))) 
	 	printf("%c",(s[x->value]));
	 print(x->ch[1]);
}

void Judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main(){
//	Judge();
	scanf("%s",s+1);
	scanf("%d",&m);
    n=strlen(s+1);
	
	zero=newnode(NULL,0);
	nothing=build(zero,1,n);
	nothing->pre=zero;
	zero->ch[1]=nothing;
	root=zero;
	
	select(NULL,n+1);
	nplus1=newnode(NULL,n+1);
	nplus1->ch[0]=root;
	root->pre=nplus1;
	root=nplus1;
	
	for (int i=1;i<=m;i++){
		scanf("%d",&a);
		b=n-a+1;
		a+=1;b+=1;
		select(NULL,a-1);
		select(root,b+1);
		root1=root->ch[1]->ch[0];
		root1->flip^=1;
		root1->push_down();
		root->ch[1]->maintain();
		root->maintain();
//		rightt=n-b+a;
//		select(NULL,rightt);
//		select(root,n-(b-a)+1);
//		root->ch[1]->ch[0]=root1;
//		root1->pre=root->ch[1];
//		root->ch[1]->maintain();
//		root->maintain();
	}
	print(root);
	return 0;
}