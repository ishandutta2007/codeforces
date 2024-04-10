#include<bits/stdc++.h>
using namespace std;
int n,m;long long maxn=0, S[10000009];
long long solve(long long a,long long b){
	long long E=S[a];E*=(b+1);
	long long F=S[b];F*=(a+1);
	return E+F;
}
int main(){
	cin>>n>>m;
	S[0]=0;for(int i=1;i<=10000008;i++)S[i]=S[i-1]+i;
	for(int i=0;i<=m;i++){
		maxn=max(maxn,solve((m-i)*n,i));
	}
	cout<<maxn<<endl;
	return 0;
}