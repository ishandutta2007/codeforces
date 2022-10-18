#include<bits/stdc++.h>

using namespace std;


int main(){
	int p,y;
	cin>>p>>y;
	for(int i=y;i>=p+1;i--){
		int cur=i;
		bool ok=1;
		for(int i=2;i*i<=cur;i++){
			if((cur%i==0)&&(i<=p||cur/i<=p))ok=0;
		}
		if(ok){
			cout<<i;
			return 0;
		}
	}	
	cout<<-1;
	return 0;
}