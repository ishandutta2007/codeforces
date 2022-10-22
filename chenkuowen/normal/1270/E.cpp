#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e3;
struct C{ int x,y; }a[MAX_N];
int n;
int upper(int);
void check(){
	vector<int> ans;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i)
		if((a[i].x&1)^(a[i].y&1)) ++cnt1;
		else{
			++cnt2;
			ans.push_back(i);
		}
	if(cnt1>0&&cnt2>0){
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d ",x);
		exit(0);
	}
}
void check2(){
	vector<int> x,y; 
	x.resize(n+1); y.resize(n+1);
	for(int i=1;i<=n;++i){
		x[i]=a[i].x,y[i]=a[i].y;
		a[i].x=upper(x[i]-y[i]);
		a[i].y=upper(x[i]+y[i]);
	}
	check();
	for(int i=1;i<=n;++i){
		a[i].x=x[i];
		a[i].y=y[i];
	}
}
int upper(int x){
	if(x%2==0) return x/2;
	else return (x+1)/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	while(1){
		check();
		check2();
		for(int i=1;i<=n;++i){
			a[i].x=upper(a[i].x);
			a[i].y=upper(a[i].y);
//			printf("(%d %d)",a[i].x,a[i].y);
		}
//		if(a[1].x==0) exit(0);
//		puts("");
		
	}
	return 0;
}