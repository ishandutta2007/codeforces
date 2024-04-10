#include<bits/stdc++.h>

using namespace std;

int main(){
	char o[2],p[2];
	cin>>o;
	bool ok=0;
	for(int i=0;i<5;i++){
		cin>>p;
		if(p[0]==o[0]||p[1]==o[1]) ok=1;
	}
	if(ok)cout<<"YES";
	else cout<<"NO";
	return 0;
}