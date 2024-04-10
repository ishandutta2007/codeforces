#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
char s[MAXN];
int main(){
	scanf("%s",s);
	char t[6]={'h','e','i','d','i','\0'};
	int slen = strlen(s);
	int tlen = strlen(t);
	for (int i=0,j=0;i<slen;i++){
		if (s[i]==t[j]){
			j++;
			if (j==tlen){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}