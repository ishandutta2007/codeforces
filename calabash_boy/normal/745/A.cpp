#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(){
	char s[55];
	char tmp[55][55];
	int length=0;
	int ans=0;
	for (int i=0;i<=51;i++)
		s[i]='!';
	cin>>s;
	for (int i=0;i<=51;i++){
		if (s[i]>'z'||s[i]<'a') break;
		else {
			length++;
		}
	}
	for (int i=0;i<=length-1;i++){
		for (int j=i;j<=length-1;j++)
			tmp[i][j-i]=s[j];
		for (int j=0;j<=i-1;j++)
			tmp[i][length-i+j]=s[j];
		bool flag=1;
		for (int j=0;j<=i-1;j++){
			bool hhh=0;
			for (int k=0;k<=length-1;k++){
				if (tmp[i][k]!=tmp[j][k]){
					hhh=1;
					break;
				}
			}
			if (!hhh){
				flag=0;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}