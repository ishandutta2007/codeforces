#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,w,mi,ma,ans;
int a[1005],x[1005];
int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x[0]=0;
	mi=1000000001;
	ma=-1000000001;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]+a[i];
		mi=min(mi,x[i]);
		ma=max(ma,x[i]);
	}
	int small=0-mi;
	if(small<0){
		small=0;
	}
	int big=w-ma;
	if(big>w){
		big=w;
	}
	cout<<max(0,big-small+1);
	return 0;
}