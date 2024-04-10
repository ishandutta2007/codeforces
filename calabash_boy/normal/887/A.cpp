#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[maxn];
int n;
int main(){
	scanf("%s",s);
	n = strlen(s);
	int first = -1;
	for (int i=0;i<n;i++){
		if (s[i]=='1'){
			first = i;
			break;
		}
	}
	if (first==-1){
		cout<<"no"<<endl;
		return 0;
	}
	int x =0;
	for (int i=first;i<n;i++){
		if (s[i]=='0')x++;
	}
	if (x>=6)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}