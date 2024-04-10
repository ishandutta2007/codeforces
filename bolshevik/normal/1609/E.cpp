#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10,B=350;
int n,q,bl[o],cnt[o],ans,x[o],y[o],mnx[B],mny[B],v[B],fx[B],fy[B];char s[o],t[2];
inline void build(int pos){
	int L=pos,R=pos;
	for(;L&&bl[L-1]==bl[L];--L);
	for(;bl[R+1]==bl[R];++R);
	mnx[bl[pos]]=mny[bl[pos]]=v[bl[pos]]=o;
	for(int i=L;i<=R;++i) v[bl[pos]]=min(v[bl[pos]],(mnx[bl[pos]]=min(mnx[bl[pos]],x[i]))+y[i]),mny[bl[pos]]=min(mny[bl[pos]],y[i]);
	mnx[bl[pos]]+=fx[bl[pos]];mny[bl[pos]]+=fy[bl[pos]];v[bl[pos]]+=fx[bl[pos]]+fy[bl[pos]];
}
inline void modifyx(int pos,int val){
	for(int i=pos;bl[i]==bl[pos];++i) x[i]+=val;
	build(pos);
	for(int i=bl[pos]+1;i<=bl[n];++i) mnx[i]+=val,v[i]+=val,fx[i]+=val;
}
inline void modifyy(int pos,int val){
	for(int i=pos;bl[i]==bl[pos];++i) y[i]+=val;
	build(pos);
	for(int i=bl[pos]+1;i<=bl[n];++i) mny[i]+=val,v[i]+=val,fy[i]+=val;
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;++i) ++cnt[s[i]];
	for(int i=0;i<=n;++i) bl[i]=i/B+1;
	for(int i=1;i<=n;++i){
		x[i]=x[i-1];y[i]=y[i-1];
		if(s[i]=='a') ++x[i];
		else if(s[i]=='b') --x[i],++y[i];
		else --y[i];
	}
	for(int i=0;i<=n;++i) if(bl[i]^bl[i+1]) build(i);
	for(int pos,deltx,delty;q--;printf("%d\n",min(min(ans,cnt['a']),min(cnt['b'],cnt['c'])))){
		scanf("%d%s",&pos,t);ans=o;deltx=delty=0;
		if(s[pos]=='a') --deltx;
		else if(s[pos]=='b') ++deltx,--delty;
		else ++delty;
		--cnt[s[pos]];++cnt[s[pos]=t[0]];
		if(s[pos]=='a') ++deltx;
		else if(s[pos]=='b') --deltx,++delty;
		else --delty;
		if(deltx) modifyx(pos,deltx);
		if(delty) modifyy(pos,delty);
		for(int i=1,j=o;i<=bl[n];j=min(j,mnx[i++])) ans=min(ans,min(v[i],j+mny[i])+cnt['c']);
	}
	return 0;
}