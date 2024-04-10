#include<bits/stdc++.h>
using namespace std;
int main(){
	long long r;
	cin>>r;
	r--;
	if(r%2||r==0||r==2){
		cout<<"NO";
		return 0;
	}
	else
		cout<<1<<' '<<(r-2)/2;
}