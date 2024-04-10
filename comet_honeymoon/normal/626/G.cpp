#include<bits/stdc++.h>
#define db long double
#pragma optimize("O2")
using namespace std;

int N,ST,Q;
int P[200005],L[200005],T[200005];

struct Node{
	int x,t;
	db val;
	void calc(){
		if(t==-1) val=1e18;
		else if(t>=L[x]) val=0;
		else val=(db)P[x]*L[x]/(t+L[x]+1)/(t+L[x]);
	}
	Node (int x0=0,int t0=-1){x=x0,t=t0;calc();}
	bool operator <(const Node b)const{
		return abs(val-b.val)>1e-10?val<b.val:x<b.x;
	}
};
multiset<Node> M1,M2;

db ANS;
#define mNi multiset<Node>::iterator
void Dec(){
	mNi tmp=M2.begin();
	ANS-=tmp->val;
	int x=tmp->x;
	M1.erase(Node(x,T[x]));M2.erase(Node(x,T[x]-1));
	T[x]--;
	M1.insert(Node(x,T[x]));M2.insert(Node(x,T[x]-1));
}
void Inc(){
	mNi tmp=--M1.end();
	ANS+=tmp->val;
	int x=tmp->x;
	M1.erase(Node(x,T[x]));M2.erase(Node(x,T[x]-1));
	T[x]++;
	M1.insert(Node(x,T[x]));M2.insert(Node(x,T[x]-1));
}

db spcalc(int x,int t){
	return (db)P[x]*min(t,L[x])/(min(t,L[x])+L[x]);
}

int main(){
	scanf("%d%d%d",&N,&ST,&Q);
	for(int i=1;i<=N;i++) scanf("%d",&P[i]);
	for(int i=1;i<=N;i++) scanf("%d",&L[i]);
	for(int i=1;i<=N;i++) M1.insert(Node(i,0)),M2.insert(Node(i,-1));
	while(ST--) Inc();
	while(Q--){
		int flg,x;scanf("%d%d",&flg,&x);
		M1.erase(Node(x,T[x]));M2.erase(Node(x,T[x]-1));ANS-=spcalc(x,T[x]);
		if(flg==1) L[x]++;else L[x]--;
		M1.insert(Node(x,T[x]));M2.insert(Node(x,T[x]-1));ANS+=spcalc(x,T[x]);
		while(((--M1.end())->val)>(M2.begin()->val)+1e-10) Dec(),Inc();
		printf("%.9Lf\n",ANS);
	}
}