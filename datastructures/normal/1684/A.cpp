#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath> 
using namespace std;
int t,n;
char s[1005];
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		if (n==2)cout<<s[2]<<endl;
		else{
			sort(s+1,s+1+n);
			cout<<s[1]<<endl;
		}
	}
	return 0;
}