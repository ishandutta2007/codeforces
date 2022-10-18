#include<bits/stdc++.h>

using namespace std;

int x;

int main(){
	cin>>x;
	for(int a=1;a<=x;a++){
		for(int b=1;b<=a;b++){
			if(a%b) continue;
			if(a*b<=x) continue;
			if(a/b>=x) continue;
			cout<<a<<' '<<b;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}