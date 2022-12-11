#include <iostream>
#include <algorithm>
using namespace std;
int a[210],b[210],na,nb;
bool k=false;
int main(){
	cin>>na>>nb;
	for(int i=1;i<=na;i++)cin>>a[i];
	for(int i=1;i<=nb;i++)cin>>b[i];
	sort(b+1,b+1+nb);
	for(int i=1,count=0;i<=na;i++)
		if(!a[i])a[i]=b[nb-count++];
	for(int i=2;i<=na;i++)
		if(a[i-1]>=a[i])k=true;
	cout<<(k?"Yes":"No")<<endl;
	return 0;
}