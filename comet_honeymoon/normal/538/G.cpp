#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;ll L;
struct node{
	ll a,b,x,y;
	bool operator <(const node b)const{return this->b<b.b;}
}A[200005];

ll lx=-4e18,rx=4e18,ly=-4e18,ry=4e18;
/*
2 11
1 0 1
12 0 2
*/

int main(){
	scanf("%d%lld",&N,&L);
	for(int i=1;i<=N;i++){
		ll tt,tx,ty;scanf("%lld%lld%lld",&tt,&tx,&ty);
		if((tt^tx^ty)&1){printf("NO\n");return 0;}
		A[i].a=tt/L,A[i].b=tt%L,A[i].x=(tx+ty+tt)/2,A[i].y=(ty-tx+tt)/2;
	}
	N++;
	N++;A[N].a=-1;A[N].b=L;
	sort(A+1,A+N+1);
	for(int i=2;i<=N;i++){
		ll a=A[i].a-A[i-1].a,b=A[i].b-A[i-1].b;
		if(!a){
			if(A[i].x-A[i-1].x>b||A[i].x-A[i-1].x<0){printf("NO\n");return 0;}
			if(A[i].y-A[i-1].y>b||A[i].y-A[i-1].y<0){printf("NO\n");return 0;}
		}
		if(a>0){
			lx=max(lx,(ll)ceil((A[i].x-A[i-1].x-b)/(long double)a));
			rx=min(rx,(ll)floor((A[i].x-A[i-1].x)/(long double)a));
			ly=max(ly,(ll)ceil((A[i].y-A[i-1].y-b)/(long double)a));
			ry=min(ry,(ll)floor((A[i].y-A[i-1].y)/(long double)a));
		}
		if(a<0){
			lx=max(lx,(ll)ceil((A[i-1].x-A[i].x)/(long double)(-a)));
			rx=min(rx,(ll)floor((A[i-1].x-A[i].x+b)/(long double)(-a)));
			ly=max(ly,(ll)ceil((A[i-1].y-A[i].y)/(long double)(-a)));
			ry=min(ry,(ll)floor((A[i-1].y-A[i].y+b)/(long double)(-a)));
		}
	}
	if(lx>rx||ly>ry){printf("NO\n");return 0;}
	for(int i=2;i<=N;i++){
		ll dx=(A[i].x-A[i].a*lx)-(A[i-1].x-A[i-1].a*lx);
		ll dy=(A[i].y-A[i].a*ly)-(A[i-1].y-A[i-1].a*ly);
		ll b=A[i].b-A[i-1].b;
		while(b--){
			if(dx>0){
				dx--;
				if(dy>0) printf("U"),dy--;
				else printf("R");
			}
			else{
				if(dy>0) printf("L"),dy--;
				else printf("D");
			}
		}
	}
}