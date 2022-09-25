#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,k,ind;
	cin >> n >> k;
	string str;
	cin >> str;
	ind=0;
	while(k>0&&ind<n){
		if(ind==0&&n>1){
			if(str[ind]!='1'){
				str[ind]='1';
				k--;
			}
		}
		else{
			if(str[ind]!='0'){
				str[ind]='0';
				k--;
			}
		}
		ind++;
	}
	cout << str << endl;
	return 0;
}