#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[111],b[111],ans[222];
int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		for(int i=1,t=0,x;i<=n;++i)cin>>x,printf("%d ",t^(t&x)),t=x^(t^(t&x));
		puts("");
	}
}