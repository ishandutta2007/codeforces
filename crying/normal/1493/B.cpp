#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int allow[10]={1,1,1,0,0,1,0,0,1,0},rev[10]={0,1,5,0,0,2,0,0,8,0};
int T,hb,mb;
int h,m;
void output(){
	if(h<=9)printf("0");
	printf("%d:",h);
	if(m<=9)printf("0");
	printf("%d\n",m);
}
bool valid(int h,int m){
	int a=h/10,b=h%10,c=m/10,d=m%10;
	if(!allow[a]||!allow[b]||!allow[c]||!allow[d])return false;
	a=rev[a],b=rev[b],c=rev[c],d=rev[d];
	if(d*10+c<hb && b*10+a<mb)return true;
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d:%d",&hb,&mb,&h,&m);
		//hb*mb
		rep(i,1,hb*mb){
			if(valid(h,m))goto END;
			m++;if(m==mb){m=0;h++;if(h==hb)h=0;}	
		} 
		END:output();
	}
	return 0;
}