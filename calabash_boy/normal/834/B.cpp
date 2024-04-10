#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000050;
int n,k;
char s[MAX];
int nowG = 0;
map<char,int> startIndex,endIndex;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int len = strlen(s+1);
	for (int i = 1;i<=len;i++){
		if (startIndex[s[i]]==0){
			startIndex[s[i]] = i;
		}
		endIndex[s[i]]=i;
	}
	for (int nows = 0;nows<=len;nows++){
		for (char i = 'A';i<='Z';i++){
			if (startIndex[i]==nows+1){
				nowG++;
			}
			if (endIndex[i]==nows&&endIndex[i]!=0){
				nowG--;
			}
		}
		if (nowG>k){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}