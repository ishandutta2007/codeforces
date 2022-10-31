#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
	int round=0;
	int now=1;
	cin>>m>>n;
	while (true){
		if (round){
			if (n<now){
				cout<<"Valera"<<endl;
				return 0;
			}else{
				n-=now;
			}
		}else{
			if (m<now){
				cout<<"Vladik"<<endl;
				return 0;
			}else{
				m-=now;
			}
		}
		now++;
		round=!round;
	}
	return 0;
}