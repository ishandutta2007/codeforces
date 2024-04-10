#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){ 
	for(auto t:y) t<x?x=t:0;
}
template<class T> inline void dmax(T& x,vector<T> y){
	for(auto t:y) t>x?x=t:0;
}
const int MAX_N=1<<21|5;
int a[MAX_N],h,g;
vector<int> ans;
void f(int a[],int i){
	if(a[i+i]==0&&a[i+i+1]==0){
		a[i]=0;
	}else if(a[i+i]>a[i+i+1]){
		a[i]=a[i+i];
		f(a,i+i);
	}else{
		a[i]=a[i+i+1];
		f(a,i+i+1);
	}
}
bool check(int a[],int i){
	if(i>=1<<g) return a[i]!=0;
	if(a[i+i]>a[i+i+1]) return check(a,i+i);
	else return check(a,i+i+1);
}
void solve(int a[],int i){
	while(check(a,i)){
		f(a,i);
		ans.push_back(i);
	}
	if(a[i]==0) return;
	solve(a,i+i);
	solve(a,i+i+1);
}
	
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&h,&g); 
		memset(a,0,sizeof(int)*((1<<h+1)+1));
		ans.clear();
		for(int i=1;i<1<<h;++i) scanf("%d",&a[i]);
		solve(a,1);
		ll sum=0;
		for(int i=1;i<1<<g;++i) sum+=a[i];
		printf("%lld\n",sum);
		for(auto x:ans) printf("%d ",x); puts("");
	}
	return 0;
}