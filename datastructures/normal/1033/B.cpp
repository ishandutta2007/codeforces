#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
bool isp(int x){
	if (x==1)return 0;
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
int t;
int a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		if (a>b+1||(!isp(a+b)))puts("NO");
		else puts("YES");
	}
	return 0;
}