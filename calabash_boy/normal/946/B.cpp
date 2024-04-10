#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
void work(){
	if (a==0||b==0)return;
	else if (a>=2*b){
		a%=(2*b);
		work();
	}else if (b>=2*a){
		b%=(2*a);
		work();
	}else{
		return;
	}
}
int main(){
	cin>>a>>b;
	work();
	cout<<a<<" "<<b<<endl;
	return 0;
}