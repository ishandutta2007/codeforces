#include<iostream>
using namespace std;
int main(){
	int cnt=0;
	string ans;
	cin>>cnt;
	ans=cnt&1?"contest":"home";
	cout<<ans;
	return 0;
}