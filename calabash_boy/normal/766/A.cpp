#include<iostream>
#include<string.h>
using namespace std;
char s1[100005],s2[100005];
int main(){
	cin>>s1;
	cin>>s2;
	if (strcmp(s1,s2)==0){
		cout<<-1;
	}else if (strlen(s1)==strlen(s2)){
		cout<<strlen(s1);		
	}else if (strlen(s1)>strlen(s2)){
		cout<<strlen(s1);
	}else{
		cout<<strlen(s2);
	}
	return 0;
}