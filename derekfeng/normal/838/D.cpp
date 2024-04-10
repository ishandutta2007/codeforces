#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int myp(int x,int t){
	int ans=1,res=x;
	for(;t;res=(ll)res*res%M,t>>=1)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d",(ll)(n+1-m)*myp(n+1,M-2)%M*myp(2*n+2,m)%M);
}