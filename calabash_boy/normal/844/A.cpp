#include<bits/stdc++.h>
using namespace std;
char s[10000];
bool has[1000];

int main(){
	scanf("%s",s);
	int n;
	cin>>n;
	int tot=0;
	for (int i=0;i<strlen(s);i++){
		has[s[i]] = true;
	}
	for (int i='a';i<='z';i++){
		if (has[i]){
			tot++;
		}
	}
	if (tot>=n){
		cout<<0<<endl;
	}else{
		if (n<=strlen(s)&&n<=26){
			cout<<n-tot<<endl;
		}else{
			cout<<"impossible"<<endl;
		}
	}
	return 0;
}