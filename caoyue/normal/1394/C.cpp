#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int n;
char s[N];
int X[N],Y[N];
bool pd(int l1,int r1,int u1,int d1,int l2,int r2,int u2,int d2){
	if(l1>r1||l2>r2)return 0;
	if(d1>u1||d2>u2)return 0;
	if((r2+u2)<l1*2)return 0;
	if((d2+l2)>r1*2)return 0;
	if((r2-d2)<d1*2)return 0;
	if((l2-u2)>u1*2)return 0;
	if(l1+d1>r2)return 0;
	if(r1+u1<l2)return 0;
	if(l1-u1>u2)return 0;
	if(r1-d1<d2)return 0;
	return 1;
}
bool check(int k){
	int l1=0,r1=INF+1e6,u1=INF+1e6,d1=0,l2=1,r2=INF*2,u2=INF*2,d2=-INF*2;
	rep(i,n){
		l1=max(l1,X[i]-k);
		r1=min(r1,X[i]+k);
		u1=min(u1,Y[i]+k);
		d1=max(d1,Y[i]-k);
		l2=max(l2,X[i]+Y[i]-k-k);
		r2=min(r2,X[i]+Y[i]+k+k);
		u2=min(u2,X[i]-Y[i]+k);
		d2=max(d2,X[i]-Y[i]-k);
	}
	if(pd(l1,r1,u1,d1,l2+(l2&1),r2-(r2&1),u2-(u2&1),d2+(d2&1)))return 1;
	if(pd(l1,r1,u1,d1,l2+(l2&1^1),r2-(r2&1^1),u2-(u2&1^1),d2+(d2&1^1)))return 1;
	return 0;
}
void solve(int A,int B){
	rep(i,A)putchar('N');
	rep(i,B)putchar('B');
	return;
}
void gg(int l1,int r1,int u1,int d1,int l2,int r2,int u2,int d2){
	if(2*l1<=(d2+l2)&&(d2+l2)<=2*r1&&2*d1<=(l2-d2)&&(l2-d2)<=2*u1){
		solve((d2+l2)/2,(l2-d2)/2);
		return;
	}
	rep0(i,2){
		if(l1+i>r1)continue;
		REP(j,d1,u1){
			if(l2<=l1+i+j&&l1+i+j<=r2&&d2<=l1+i-j&&l1+i-j<=u2){
				solve(l1+i,j);
				return;
			}
		}
	}
	rep0(i,2){
		if(r1-i<l1)continue;
		REP(j,d1,u1){
			if(l2<=r1-i+j&&r1-i+j<=r2&&d2<=r1-i-j&&r1-i-j<=u2){
				solve(r1-i,j);
				return;
			}
		}
	}
	rep0(i,2){
		if(d1+i>u1)continue;
		REP(j,l1,r1){
			if(l2<=d1+i+j&&d1+i+j<=r2&&d2<=j-(d1+i)&&j-(d1+i)<=u2){
				solve(j,d1+i);
				return;
			}
		}
	}
	rep0(i,2){
		if(u1-i<d1)continue;
		REP(j,l1,r1){
			if(l2<=u1-i+j&&u1-i+j<=r2&&d2<=j-(u1-i)&&j-(u1-i)<=u2){
				solve(j,u1-i);
				return;
			}
		}
	}
	return;
}
void print(int k){
	int l1=0,r1=INF+1e6,u1=INF+1e6,d1=0,l2=1,r2=INF*2,u2=INF*2,d2=-INF*2;
	rep(i,n){
		l1=max(l1,X[i]-k);
		r1=min(r1,X[i]+k);
		u1=min(u1,Y[i]+k);
		d1=max(d1,Y[i]-k);
		l2=max(l2,X[i]+Y[i]-k-k);
		r2=min(r2,X[i]+Y[i]+k+k);
		u2=min(u2,X[i]-Y[i]+k);
		d2=max(d2,X[i]-Y[i]-k);
	}
	if(pd(l1,r1,u1,d1,l2+(l2&1),r2-(r2&1),u2-(u2&1),d2+(d2&1)))gg(l1,r1,u1,d1,l2+(l2&1),r2-(r2&1),u2-(u2&1),d2+(d2&1));
	else gg(l1,r1,u1,d1,l2+(l2&1^1),r2-(r2&1^1),u2-(u2&1^1),d2+(d2&1^1));
	puts("");
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s+1);
		int k=strlen(s+1);
		X[i]=Y[i]=0;
		rep(j,k){
			X[i]+=(s[j]=='N');
			Y[i]+=(s[j]=='B');
		}
	}
	int l=0,r=1000000;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(check(l)){
		printf("%d\n",l);
		print(l);
	}
	else{
		printf("%d\n",r);
		print(r);
	}
	return 0;
}