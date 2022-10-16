#include <iostream>
#include <cstdio>
using namespace std;
int t;
string a,b,c;
int flag;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		flag=1;
		for (int i=0;i<a.size();i++){
			int s=0;
			if (a[i]==c[i])s=1;
			if (b[i]==c[i])s=1;
			if (s==0)flag=0;
		}
		if (flag==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}