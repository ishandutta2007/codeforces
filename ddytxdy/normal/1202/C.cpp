#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=2e5+50;
int t,len,x,y,dx[4]={-1,0,0,1},dy[4]={0,-1,1,0},a[N],mxx,mnx,mxy,mny;char c[N];LL ans;
void cmax(int &x,int y){y>x?x=y:0;}
void cmin(int &x,int y){y<x?x=y:0;}
bool check1(){
	x=0;y=0;int flag=0;
	if(x==mxx)flag=1;if(x==mnx)flag=2;
	for(int i=1;i<=len;i++){
		x+=dx[a[i]];y+=dy[a[i]];
		if(x==mxx){
			if(!flag)flag=1;
			else if(flag==2)flag=3;
			else if(flag==4)return 0;
		}
		if(x==mnx){
			if(!flag)flag=2;
			else if(flag==1)flag=4;
			else if(flag==3)return 0;
		}
	}
	return 1;
}
bool check2(){
	x=0;y=0;int flag=0;
	if(y==mxy)flag=1;if(y==mny)flag=2;
	for(int i=1;i<=len;i++){
		x+=dx[a[i]];y+=dy[a[i]];
		if(y==mxy){
			if(!flag)flag=1;
			else if(flag==2)flag=3;
			else if(flag==4)return 0;
		}
		if(y==mny){
			if(!flag)flag=2;
			else if(flag==1)flag=4;
			else if(flag==3)return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		len=strlen(c+1);x=0;y=0;
		for(int i=1;i<=len;i++){
			if(c[i]=='W')a[i]=0;
			if(c[i]=='A')a[i]=1;
			if(c[i]=='D')a[i]=2;
			if(c[i]=='S')a[i]=3;
		}
		mxx=mnx=mxy=mny=0;
		for(int i=1;i<=len;i++){
			x+=dx[a[i]];y+=dy[a[i]];
			cmax(mxx,x);cmin(mnx,x);
			cmax(mxy,y);cmin(mny,y);
		}
		ans=1ll*(mxx-mnx+1)*(mxy-mny+1);
		if(mxx-mnx+1>=3&&check1())ans=min(ans,1ll*(mxx-mnx)*(mxy-mny+1));
		if(mxy-mny+1>=3&&check2())ans=min(ans,1ll*(mxx-mnx+1)*(mxy-mny));
		cout<<ans<<endl;
	}
	return 0;
}