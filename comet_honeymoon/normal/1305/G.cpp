#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxN=262144; 
int N;
int A[maxN],fa[maxN];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
struct node{
	int p,c;
	node(int p0=-1,int c0=-1){p=p0;c=c0;}
	bool operator <(const node b)const{
		return p<b.p;
	}
	bool operator >(const node b)const{
		return p>b.p;
	}
	operator bool(){return p!=-1;}
};
node F[maxN][2];
node maxE[maxN];
int ANS;

signed main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&A[i]),ANS-=A[i];A[N++]=0;
	for(int i=0;i<N;i++) fa[i]=i;
	int cnt=N;
	while(cnt!=1){
		for(int s=0;s<(1<<18);s++)
			F[s][0]=F[s][1]=node();
		for(int i=0;i<N;i++){
			node tmp(A[i],find(i));
			if(tmp>F[A[i]][0]){
				if(F[A[i]][0].c!=tmp.c) F[A[i]][1]=F[A[i]][0]; 
				F[A[i]][0]=tmp;
			}
			if(tmp>F[A[i]][1]&&tmp.c!=F[A[i]][0].c) F[A[i]][1]=tmp;
		}
		for(int i=0;i<18;i++)
		for(int s=0;s<(1<<18);s++) if((s>>i)&1)
		for(int d=0,t=s^(1<<i);d<2;d++){
			node tmp=F[t][d];
			if(tmp>F[s][0]){
				if(F[s][0].c!=tmp.c) F[s][1]=F[s][0]; 
				F[s][0]=tmp;
			}
			if(tmp>F[s][1]&&tmp.c!=F[s][0].c) F[s][1]=tmp;
		}
		
		for(int i=0;i<N;i++) maxE[i]=node();
		for(int i=0;i<N;i++){
			int s=((1<<18)-1)^A[i],c=find(i);
			if(F[s][0])if(F[s][0].c!=c)
				{if(node(A[i]+F[s][0].p,F[s][0].c)>maxE[c]) maxE[c]=node(A[i]+F[s][0].p,F[s][0].c);}
			else if(F[s][1])
				{if(node(A[i]+F[s][1].p,F[s][1].c)>maxE[c]) maxE[c]=node(A[i]+F[s][1].p,F[s][1].c);} 
		}
		for(int u=0;u<N;u++) if(u==find(u)){
			int v=maxE[u].c;
			if(find(u)==find(v)) continue;
			cnt--;fa[find(u)]=find(v);ANS+=maxE[u].p;
		}
	}
	printf("%lld\n",ANS);
}