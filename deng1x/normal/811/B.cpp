#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAXN 10010
#define MAXP 400000

int N,M;
struct Tree{
	Tree *lc;
	int sz;
	Tree *rc;
}Pool[MAXP];
Tree *New=Pool;
Tree *null;
Tree *P[MAXN];

int Ori[MAXN];
int Loc[MAXN];
pair<int,int> V[MAXN];

void Read(int &x){
	char t=getchar();
	while(!('0'<=t&&t<='9')) t=getchar();
	for(x=t-'0',t=getchar();'0'<=t&&t<='9';x=(x<<1)+(x<<3)+t-'0',t=getchar());
}

Tree *Get(Tree *lc,int sz,Tree *rc){
	New->lc=lc;
	New->sz=sz;
	New->rc=rc;
	return New++;
}

void Renumber(){
	sort(V+1,V+N+1);
	int temp=1;
	Loc[V[1].second]=temp;
	Ori[temp]=V[1].first;
	for(int i=2;i<=N;++i){
		temp+=(V[i].first!=V[i-1].first);
		Loc[V[i].second]=temp;
		Ori[temp]=V[i].first;
	}
}

Tree *Insert(Tree *T,int loc,int Left,int Right){
	if(Left==Right)
	    return Get(0,T->sz+1,0);
	int Mid=(Left+Right)>>1;
	Tree *temp;
	if(loc<=Mid){
		temp=Insert(T->lc,loc,Left,Mid);
		return Get(temp,temp->sz+T->rc->sz,T->rc);
	}
	else{
		temp=Insert(T->rc,loc,Mid+1,Right);
		return Get(T->lc,temp->sz+T->lc->sz,temp);
	}
}

void Init(){
	Read(N);Read(M);
	int temp;
	for(int i=1;i<=N;++i){
		Read(temp);
		V[i]=make_pair(temp,i);
	}
	Renumber();
	P[0]=null;
	for(int i=1;i<=N;++i){
		P[i]=Insert(P[i-1],Loc[i],1,N);
	}
}

int Search(Tree *L,Tree *R,int k,int Left,int Right){
	if(Left==Right) 
	    return Left;
	int Mid=(Left+Right)>>1;
	if(k<=R->lc->sz-L->lc->sz){
		return Search(L->lc,R->lc,k,Left,Mid);
	}
	else{
		k-=R->lc->sz-L->lc->sz;
		return Search(L->rc,R->rc,k,Mid+1,Right);
	}
}

void Solve(){
	int l,r,k;
	for(int i=1;i<=M;++i){
		Read(l);Read(r);Read(k);
		
		printf(Ori[Search(P[l-1],P[r],k - l + 1,1,N)] == Loc[k] ? "Yes\n" : "No\n");
	}
}

int main(){
	
	null=Get(0,0,0);
	null->lc=null;
	null->rc=null;
	
	Init();
	Solve();
	return 0;
}