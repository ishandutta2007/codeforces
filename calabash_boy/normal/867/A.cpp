#include<bits/stdc++.h>
using namespace std;
const int maxn = 104;
char s[maxn];
int n;
int cnt0=0,cnt1=0;
int main(){
	scanf("%d%s",&n,s);
	for (int i=1;i<n;i++){
		if (s[i]!=s[i-1]){
			if (s[i]=='F'){
				cnt0++;
			}else{
				cnt1++;
			}
		}
	}
	if (cnt0>cnt1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}