/******************
*  Writer: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

long long n,m,k;

long long fun(long long x){
	long long res=0;
	long long w=1;
	for(long long i=n;i>=1;i--){
		while( (w+1)*i<=x && w<m ){
			w++;
		}
		if(w*i<=x){
			res+=w;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	long long l=1,r=n*m,d,res;
	while(l<=r){
		d=(l+r)/2;
		if(fun(d)>=k){
			res=d;
			r=d-1;
		}else{
			l=d+1;
		}
	}
	cout<<res<<endl;
	
	return 0;
}