#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	char dir[20];
	int dis=0;
	int now=0;
	for (int i=1;i<=n;i++){
		cin>>dis;
		cin>>dir;
		switch(dir[0]){
			case 'S':if (now+dis<=20000) now+=dis;else {cout<<"NO";return 0;}break;
			case 'N':if (now-dis>=0) now-=dis;else {cout<<"NO";return 0;}break;
			default:if (now==0||now==20000) {cout<<"NO";return 0;}break;
		}	
	}
	if (now==0)
	cout<<"YES";
	else cout<<"NO";
	return 0;
}