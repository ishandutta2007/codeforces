#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int length[MAXN];
int n,k;
int main(){
	cin>>n>>k;
	n--;
	int delta = n%k;
	int length = n/k;
	int now =1;
	if (delta>=2){
		cout<<2*(length+1)<<endl;
	}else if (delta==1){
		cout<<2*length+1<<endl;
	}else{
		cout<<2*length<<endl;
	}
	for (int i=0;i<delta;i++){
		now++;
		cout<<"1 "<<now<<endl;
		for (int j=1;j<length+1;j++){
			now++;
			cout<<now<<" "<<now-1<<endl;
		}
	}
	for (int i=0;i<k-delta;i++){
		now++;
		cout<<"1 "<<now<<endl;
		for (int j=1;j<length;j++){
			now++;
			cout<<now<<" "<<now-1<<endl;
		}
	}
	return 0;
}