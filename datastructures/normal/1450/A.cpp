#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n;
char s[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s+1);
		sort(s+1,s+1+n);
		for (int i=1;i<=n;i++)putchar(s[i]);
		cout<<endl;
	}
	return 0;
}