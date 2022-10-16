#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[1005],emm,a1,a2;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		n--;
		for (int i=0;i<=n;i++)cin>>a[i];
		a1=a2=emm=0;
		for (int i=0;i<=n;i++){
			if (a[i]%2!=i%2){
				emm++;
				if (a[i]%2==0)a2++;
				else a1++;
			}
		}
		if (a1!=a2)cout<<-1<<endl;
		else cout<<a1<<endl;
	} 
	return 0;
}