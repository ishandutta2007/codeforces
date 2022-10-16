#include<bits/stdc++.h>
using namespace std;
bool check(long long a,long long b){
	if(a==0||b==0)return 0;
	if(!check(b%a,a))return 1;
	long long tmp=(b/a-1)%(a+1);
	if(tmp%2==1)return 1;
	if(tmp==a)return 1;
	return 0;
}
int main(){
	long long T,a,b;;
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(check(a,b))
			cout<<"First\n";
		else
			cout<<"Second\n";
	}
}