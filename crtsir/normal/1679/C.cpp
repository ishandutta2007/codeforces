#include<bits/stdc++.h>
using namespace std;
int T=1;
struct BIT{
	int dat[100003];
	BIT(){memset(dat,0,sizeof(dat));}
	int query(int x){
		int ret=0;
		while(x){
			ret+=dat[x];
			x-=(x&-x);
		}return ret;
	}
	void add(int x,int y){
		while(x<=100000){
			dat[x]+=y;
			x+=(x&-x);
		}
	}
}a,b;
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	map<int,int>mpx,mpy;
	while(q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if(tp==1){
			if(!mpx[x])a.add(x,1);mpx[x]++;
			if(!mpy[y])b.add(y,1);mpy[y]++;
		}
		if(tp==2){mpx[x]--;mpy[y]--;
			if(!mpx[x])a.add(x,-1);
			if(!mpy[y])b.add(y,-1);
		}
		if(tp==3){
			int X,Y;
			scanf("%d%d",&X,&Y);
			if(a.query(X)-a.query(x-1)==X-x+1||b.query(Y)-b.query(y-1)==Y-y+1)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
	}
}