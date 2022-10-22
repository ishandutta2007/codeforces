#include <bits/stdc++.h>
using namespace std;
const int M=720720;
int n,m,x;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++){
		cin>>x;
		if((i+j)&1)cout<<M<<" ";
		else cout<<M-x*x*x*x<<" ";
	}
}