#include<iostream>
using namespace std;
int main(){
	int answer[10];
	int max=-1;
	int temp;
	int num[4];
	for(int i=0;i<4;i++)num[i]=0;
for (int o=0;o<4;o++)
	for(int i=0;i<=9;i++){
		for(int j=0;j<o;j++)
			cout<<'0';
	 	cout<<i;
		for(int j=o+1;j<4;j++)
			cout<<'0';
		cout<<endl;
		cin>>answer[i]>>temp;
		num[o]=max>answer[i]?num[o]:i;
		max=max>answer[i]?max:answer[i];
	}
	for(int i=0;i<4;i++)
		cout<<num[i];
	return 0;
}