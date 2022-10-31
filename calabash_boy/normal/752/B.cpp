#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char f[200];
	char str1[1005],str2[1005];
	cin>>str1>>str2;
	for(char i='a';i<='z';i++)
		f[i]=0;
	for (int i=0;i<strlen(str1);i++){
		if (f[str1[i]]==0) f[str1[i]]=str2[i];
		if (f[str2[i]]==0) f[str2[i]]=str1[i];
		if (f[str1[i]]!=str2[i]||f[str2[i]]!=str1[i]){
			cout<<"-1";
			return 0;
		}
	}
	int ans=0;
	for (char i='a';i<='z';i++)
		if (f[i]>i&&f[i])ans++;
	cout<<ans<<endl;
	for (char i='a';i<='z';i++){
		if (f[i]>i&&f[i]){
			cout<<i<<' '<<f[i]<<endl;
		}
	}
	return 0;
}