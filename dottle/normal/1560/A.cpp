#include<bits/stdc++.h>
using namespace std;

int chk(int k){
	if(k%3==0)return 0;
	if(k){
		if(k%10==3)return 0;
		k/=10;
	}return 1;
} 

int t,k,i,j;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>k;
		for(i=1,j=1;i<k;i++,j++){
			while(!chk(j))
				j++;
		}while(!chk(j))j++;cout<<j<<endl;
	}
}