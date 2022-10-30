#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}A[10];
int n=4;
long long mi;
int mark[10],B[10];
void solve1(){
	int now=mark[1];
	//now at LD
	long long res=0;
	res+=abs(A[mark[2]].x-A[now].x);
	res+=abs(A[mark[3]].y-A[now].y);
	B[1]=A[mark[2]].y-A[now].y;
	B[2]=A[mark[3]].x-A[now].x;
	B[3]=A[mark[4]].x-A[now].x;
	B[4]=A[mark[4]].y-A[now].y;
	sort(B+1,B+5);
	for(int i=1;i<=4;i++){
		res+=abs(B[i]-B[2]);
	}
	if(res<mi)mi=res;
}
void solve2(){
	int now=mark[1];
	//now at LD
	long long res=0;
	res+=abs(A[mark[2]].x-A[now].x);
	res+=abs(A[mark[3]].y-A[now].y);
	B[1]=A[mark[2]].y-A[now].y;
	B[2]=A[mark[3]].x-A[mark[2]].x;
	B[3]=A[mark[4]].x-A[mark[2]].x;
	B[4]=A[mark[4]].y-A[now].y;
	sort(B+1,B+5);
	for(int i=1;i<=4;i++){
		res+=abs(B[i]-B[2]);
	}
	if(res<mi)mi=res;
}
void solve3(){
	int now=mark[1];
	//now at LD
	long long res=0;
	res+=abs(A[mark[2]].x-A[now].x);
	res+=abs(A[mark[3]].y-A[now].y);
	B[1]=A[mark[2]].y-A[mark[3]].y;
	B[2]=A[mark[3]].x-A[mark[2]].x;
	B[3]=A[mark[4]].x-A[mark[2]].x;
	B[4]=A[mark[4]].y-A[mark[3]].y;
	sort(B+1,B+5);
	for(int i=1;i<=4;i++){
		res+=abs(B[i]-B[2]);
	}
	if(res<mi)mi=res;
}
void solve4(){
	int now=mark[1];
	//now at LD
	long long res=0;
	res+=abs(A[mark[2]].x-A[now].x);
	res+=abs(A[mark[3]].y-A[now].y);
	B[1]=A[mark[2]].y-A[mark[3]].y;
	B[2]=A[mark[3]].x-A[now].x;
	B[3]=A[mark[4]].x-A[now].x;
	B[4]=A[mark[4]].y-A[mark[3]].y;
	sort(B+1,B+5);
	for(int i=1;i<=4;i++){
		res+=abs(B[i]-B[2]);
	}
	if(res<mi)mi=res;
}
void dfs(int now){
	if(now>n){
		solve1();
		solve2();
		solve3();
		solve4();
		return;
	}
	for(int i=1;i<=4;i++){
		if(mark[i])continue;
		mark[i]=now;
		dfs(now+1);
		mark[i]=0;
	}
}
int main(){
	int i,j,T;
	cin>>T;
	while(T--){
		mi=1LL*1000000*1000000;
		for(i=1;i<=n;i++)scanf("%d %d",&A[i].x,&A[i].y);
		dfs(1);
		printf("%lld\n",mi);
	}
	return 0;
}