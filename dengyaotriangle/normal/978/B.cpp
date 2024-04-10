#include<bits/stdc++.h>

using namespace std;

const int maxl=105;

char a[maxl];

int main(){
	int n;
	cin>>n;
	cin>>a;
	int cesl=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]=='x'){
			cesl++;
		}else{
			cesl=0;
		}
		if(cesl>=3) ans++;
	}
	cout<<ans;
	return 0;
}