/*








*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n,m;
int Sum[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		Sum[i]=Sum[i-1]+x;
	}
	int sum=0;
	for(int i=1;i+m-1<=n;i++)sum+=Sum[i+m-1]-Sum[i-1];
	printf("%.100lf",1.*sum/(n-m+1));
	return 0;
}