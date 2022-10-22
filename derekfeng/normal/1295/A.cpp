#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while (T--){
		int n;cin>>n;
		if (n%2==1){
			cout<<"7";for (int i=0;i<(n-3)/2;i++) cout<<"1";puts("");
		}else{
			for (int i=1;i<=n/2;i++) cout<<"1";puts("");
		}
	}
}