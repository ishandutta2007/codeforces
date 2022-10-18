#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,m;
long long x[maxn];
long long tot;
long long delta,dm;
double ans;

long long ced(long long n){
	return (n-1)*n/2;
}

int main(){
	cin>>n>>m;
	delta=ced(n);
	if(n%2==0){
		dm=ced(n/2)+ced(n/2+1);
	}else{
		dm=2*ced(n/2+1);
	}
	for(int i=0;i<m;i++){
		long long x,d;
		cin>>x>>d;
		if(d<0) tot+=x*n+dm*d;
		else tot+=x*n+delta*d;
	}
	ans=(double)(tot)/(double)(n);
	printf("%.15lf",ans);
	return 0;
}