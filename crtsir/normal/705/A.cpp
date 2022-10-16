#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x;
	cin>>x;
	cout<<"I hate "; 
	for(int i=1;i<x;i++)
		if(i%2==1)
			cout<<"that I love ";
		else
			cout<<"that I hate ";
	cout<<"it";
}