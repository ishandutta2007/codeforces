/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main(){
	cin>>n>>m>>a;
	for(int i=0;i<a.size();i++){
		string b=a.substr(0,i+1)+a;
		int cnt=0;
		for(int j=0;j+a.size()-1<b.size();j++)cnt+=b.substr(j,a.size())==a;
		if(cnt>1){
			while(--m)cout<<a.substr(0,i+1);
			cout<<a;
			return 0;
		}
	}
	return 0;
}