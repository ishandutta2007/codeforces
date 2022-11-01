//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int tot=1,ch[N*28][2],t[N*28];
inline void insert(int x,int fl){
	int p=1,c;
	t[p]+=fl;
	for(int i=26;i>=0;i--){
		c=(x>>i)&1;
		if(!ch[p][c])ch[p][c]=++tot;
		p=ch[p][c];
		t[p]+=fl;
	}
}
inline int query(int v,int k){
	int p=1,cv,ck,ret=0;
	for(int i=26;i>=0;i--){
		cv=(v>>i)&1;ck=(k>>i)&1;
		if(ck)ret+=t[ch[p][cv]];
		p=ch[p][cv^ck];
	}
	return ret;
}
int main(){
	int Q=read(),op,x;
	while(Q--){
		op=read();x=read();
		if(op==1)insert(x,1);
		else if(op==2)insert(x,-1);
		else cout<<query(x,read())<<"\n";
	}
	return (0-0);
}