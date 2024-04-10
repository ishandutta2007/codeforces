#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int ct=0;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='1'){
			ct++;
		}
	}
	if(l%2==1&&ct>1){
		printf("%d",l/2+1);
	}else{
		printf("%d",l>>1);
	}
	return 0;
}