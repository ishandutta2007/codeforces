#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long f[maxn];
int fs;
int n;

long long ga(int bc){
	return (long long)(1+n-bc+1)*(long long)(n/bc)/2ll;
}

int main(){
	cin>>n;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			f[++fs]=ga(i);
			if(i*i!=n) f[++fs]=ga(n/i); 
		} 
		
	} 
	sort(f+1,f+fs+1);
	for(int i=1;i<=fs;i++) cout<<f[i]<<' ';
	return 0;
}