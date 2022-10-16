#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,k,q;
int a[200005];
int B=400;
int Bcnt,Bid[200005],Bl[200005],Br[200005],tag[200005],pre[200005][2],fir[200005][2];
int pos[2];
void pushup(int id){
	if (tag[id]==1){
		for (int i=Bl[id];i<=Br[id];i++)a[i]^=1;
		tag[id]=0;
	}
	pos[0]=pos[1]=Bl[id]-1;
	for (int i=Bl[id];i<=Br[id];i++){
		pos[a[i]]=i;
		fir[i][a[i]]=i,fir[i][a[i]^1]=0;
		pre[i][0]=pos[0],pre[i][1]=pos[1];
		if (i-k-1>=Bl[id]&&pre[i-k-1][a[i]]>=Bl[id])fir[i][a[i]]=fir[pre[i-k-1][a[i]]][a[i]];
	}
	return;
}
void getBlock(){
	for (int i=1;i<=n;i++){
		if ((i-1)%B==0)Bcnt++;
		Bid[i]=Bcnt;
		if (Bl[Bcnt]==0)Bl[Bcnt]=i;
		Br[Bcnt]=i;
	}
	for (int i=1;i<=Bcnt;i++)pushup(i);
	return;
}
void upd(int l,int r){
	int lid=Bid[l],rid=Bid[r];
	if (lid==rid){
		for (int i=l;i<=r;i++)a[i]^=1;
		pushup(lid);
		return;
	}
	for (int i=l;i<=Br[lid];i++)a[i]^=1;
	pushup(lid);
	for (int i=Bl[rid];i<=r;i++)a[i]^=1;
	pushup(rid);
	for (int i=lid+1;i<=rid-1;i++)tag[i]^=1;
	return;
}
int getpre(int x){
	while(x>0&&(a[x]^tag[Bid[x]])!=0)x=pre[x][0^tag[Bid[x]]];
	return x;
}
int ask(int x,int y){
	y=getpre(y);
	while(y>0&&Bid[y]>Bid[x]){
		y-=k+1;
		if (y>0){
			y=getpre(y);
			if (Bid[y]>Bid[x])y=fir[y][tag[Bid[y]]];
		}
	}
	while(y>x){
		y-=k+1;
		if (y>=x)y=getpre(y);
	}
	if (y<x)return 1;
	return 0;
}
int main(){
	cin>>n>>k>>q;
	for (int i=1;i<=n;i++){
		a[i]=read();
		a[i]=(a[i]&1)^1;
	}
	getBlock();
	while(q--){
		int opt,x,y,z;
		opt=read();
		if (opt==1){
			x=read(),y=read(),z=read();
			if (z&1)upd(x,y);
		}
		else{
			x=read(),y=read();
			if (ask(x,y)==1)puts("1");
			else puts("2");
		}
	}
	return 0;
}