#include<bits/stdc++.h>

using namespace std;

unsigned long long fdmn(unsigned long long a,unsigned long long b){
	if(a<b) return a;
	return b;
}

unsigned long long fdmx(unsigned long long a,unsigned long long b){
	if(a>b) return a;
	return b;
}

int main(){
	int q;
	cin>>q;
	while(q--){
		unsigned long long x,y,k,ans=0,sqr,nhd;
		cin>>x>>y>>k;
		if(x>k||y>k) cout<<-1<<endl;
		else{
			if((!((k-x)&1))&&(!((k-y)&1))){
				cout<<k<<endl;
			}else if((((k-x)&1))&&(!((k-y)&1))){
				cout<<k-1<<endl;
			}else if((!((k-x)&1))&&(((k-y)&1))){
				cout<<k-1<<endl;
			}else if((((k-x)&1))&&(((k-y)&1))){
				cout<<k-2<<endl;
			}
		}
	}
	return 0;
}