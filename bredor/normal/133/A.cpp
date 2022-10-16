//  228

#include<bits/stdc++.h>
using namespace std;
int main(){
	int k=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
			k=1;
	}
	if(k==1)
		cout<<"YES";
	else
		cout<<"NO";
 
    return 0;
}