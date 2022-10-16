#include <iostream>
#include <cstdio>
using namespace std;
int a[200005],book[200005],n;
int main(){
//	freopen("1144C.in","r",stdin);
/////	freopen("1144C.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],book[a[i]]++;
	for (int i=0;i<=200000;i++){
		if (book[i]>2){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	int s=0;
	for (int i=0;i<=200000;i++)
		if (book[i])s++;
	cout<<s<<endl;
	for (int i=0;i<=200000;i++){
		if (book[i]){
			book[i]--;
			cout<<i<<' ';
		} 
	}
	cout<<endl;
	s=0;
	for (int i=200000;i>=0;i--)
		if (book[i])s++;
	cout<<s<<endl;
	for (int i=200000;i>=0;i--){
		if (book[i]){
			book[i]--;
			cout<<i<<' ';
		}
	}
	cout<<endl;
	return 0;
}