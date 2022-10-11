#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++)cout<<(char)('a'+i);
	for(int i=k;i<n;i++){if(i%2==1)cout<<'b';else cout<<'a';}cout<<endl;
	return 0;
}