#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		cout<<6+2*abs(y1-y2)<<endl;
		return 0;
	}
	if(y1==y2){
		cout<<6+2*abs(x1-x2)<<endl;
		return 0;	
	}
	cout<<2*(abs(x1-x2)+abs(y1-y2))+4<<endl;
}