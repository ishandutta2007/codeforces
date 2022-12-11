#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,sum,mn,now;char s[N];
int main(){
	scanf("%d%s",&n,s+1);mn=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			sum++;
			if(!sum)now=i+mn;
		}
		else sum--;
		if(!sum)mn=min(mn,now-i);
	}
	if(sum)puts("-1");
	else cout<<now;
	return 0;
}