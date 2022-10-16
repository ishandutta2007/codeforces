#include<iostream>
using namespace std;
int main(){
	int w;
	cin>>w;
	for(int i=2;i<w;i+=2)
		if(i%2==0&&(w-i)%i==0)
		{
			cout<<"YES";
			return 0;
		}
	cout<<"NO";
}