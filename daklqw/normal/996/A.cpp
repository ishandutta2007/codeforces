#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 
#define LL long long
int n,ans=0;
int main(){
	scanf("%d",&n);
	ans+=n/100;
	n%=100;
	ans+=n/20;
	n%=20;
	ans+=n/10;
	n%=10;
	ans+=n/5;
	n%=5;
	ans+=n;
	cout<<ans<<endl;
	return 0;
}