#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
 
long long n;
long long p[maxn];
map <long long,bool> m;
long long da,db;

long long pw(long long a,long long b){
	long long ans=1;
	while(b--) ans*=a;
	return ans;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
		m[p[i]]=1;
	}
	sort(p,p+n);
	bool oko=0;
	for(int i=0;i<31;i++){
		long long t=pw(2,i);
		for(int j=0;j<n;j++){
			if(p[j]+t>p[n-1]) break;
			if(m[p[j]+t]) {
				oko=1;
				da=p[j];
				db=p[j]+t;
				break;
				//cout<<2<<endl<<p[j]<<' '<<p[j]+t;
				//return 0; 
			}
		} 
		if(oko) break;
	} 
	if(!oko){
		cout<<1<<endl<<p[0];
		return 0;
	}
	for(int i=0;i<31;i++){
		long long t=pw(2,i);
		for(int j=0;j<n;j++){
			if(p[j]+t+t>p[n-1]) break;
			if(m[p[j]+t]&&m[p[j]+t+t]) {
				cout<<3<<endl<<p[j]<<' '<<p[j]+t<<' '<<p[j]+t+t;
				return 0; 
			}
		} 
	}
	cout<<2<<endl<<da<<' '<<db;
	return 0;
}