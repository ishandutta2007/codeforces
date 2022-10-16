#include<bits/stdc++.h>
using namespace std;
set<long long>s;
long long n;
void dfs(long long x,int a,int b){
	s.insert(x);
	if(x*10+a!=x&&x*10+a<=n)
		dfs(x*10+a,a,b);
	if(x*10+b!=x&&x*10+b<=n)
		dfs(x*10+b,a,b);
}
int main(){
	cin>>n;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			dfs(0,i,j);
	cout<<s.size()-1;
}