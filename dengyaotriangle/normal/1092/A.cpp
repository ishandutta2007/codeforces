#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int l=n/k;
		int lst=n;
		for(int i=1;i<k;i++){
			for(int j=1;j<=l;j++) cout<<(char)(i+'a'-1);
			lst-=l;
		}
		for(int i=1;i<=lst;i++) cout<<(char)(k+'a'-1);
		cout<<endl;
	} 
	return 0;
}