#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
char s[100005];
int t;
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		cout<<s[1];
		for (int i=2;i<=strlen(s+1);i+=2)cout<<s[i];
		cout<<endl;
	}
	return 0;
}