#include<bits/stdc++.h>

using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	if((a==1)||(b==1)||(c==1)){
		cout<<"YES";
		return 0;
	}
	if((a==2&&b==2)||(a==2&&c==2)||(b==2&c==2)){
		cout<<"YES";
		return 0;
	}
	if(a==3&&b==3&&c==3){
		cout<<"YES";
		return 0;
	}
	if((a==4&&b==4&&c==2)||(a==4&&b==2&&c==4)||(a==2&&b==4&&c==4)){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
}