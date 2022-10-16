#include<bits/stdc++.h>
using namespace std;
int T=1;
bool isprime(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		int n,nw=2,cnt=0;
		cin>>n;
		while(cnt<n){	
			if(isprime(nw))
				cout<<nw<<' ',cnt++;
			nw++;
		}
		cout<<endl;
	}
}