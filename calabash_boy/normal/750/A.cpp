#include<iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	int time=240-k;
	while(time>=0&&ans<=n){
		time-=ans*5;
		ans++;
	}
	ans--;
	if (time<0)
	ans--;
	cout<<ans;

	return 0;
}