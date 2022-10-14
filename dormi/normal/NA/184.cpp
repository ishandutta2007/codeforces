#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool check(string a){
	int ans=0;
	for(char i:a){
		ans+=(i-'0');
	}
	return !(ans%4);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    for(;;){
    	if(check(a)){
    		cout<<a;
    		return 0;
    	}
    	else{
    		a=to_string(stoi(a)+1);
    	}
    }
    return 0;
}