#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S,T="Bulbasur";int a[256];
int main(){
	cin>>S;int r=99999999;
	for(int i=0;i<S.size();i++){a[(int)S[i]]++;}
	for(int i=0;i<8;i++){
		int U=1;if(T[i]=='a' || T[i]=='u')U++;
		r=min(r,a[(int)T[i]]/U);
	}
	cout<<r<<endl;
	return 0;
}