#include<bits/stdc++.h>
using namespace std;
int n,k,i,nw;
int main(){
	cin>>n>>k;
	if(n==4){
		cout<<"? "<<1<<endl;
		cin>>nw;
		cout<<"? "<<1<<endl;
		cin>>nw;
		if(nw==k/2){
			cout<<"! "<<2;
			return 0;
		}
		cout<<"? "<<2<<endl;
		cin>>nw;
		if(nw==k/2){
			cout<<"! "<<3;
			return 0;
		}
		cout<<"? "<<3<<endl;
		cin>>nw;
		if(nw==k/2){
			cout<<"! "<<4;
			return 0;
		}
		cout<<"? "<<4<<endl;
		cin>>nw;
		if(nw==k/2){
			cout<<"! "<<1;
			return 0;
		}
	}
	while(1){
		cout<<"? "<<i*(i+1)/2+1<<endl;
		cin>>nw;
		if(nw!=k)break;
		i++;
	}
	if(nw<k)//cheater on the right
		for(int j=1;j<=i;j++){
			cout<<"? "<<i*(i+1)/2+j+1<<endl;
			cin>>nw;
			if(nw==k){
				cout<<"! "<<i*(i+1)/2+j+1;
				return 0;
			}
		}
	else
		for(int j=1;j<=i;j++){
			cout<<"? "<<i*(i+1)/2-j+1<<endl;
			cin>>nw;
			if(nw==k){
				cout<<"! "<<i*(i+1)/2-j+1;
				return 0;
			}
		}
}