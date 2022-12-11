#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;char s[N];
void solve(){
	scanf("%s",s+1);int len=strlen(s+1);
	// if(s[len]!='0'){puts("cyan");return;}
	int num=0,nnum=0,nnnum=0;
	for(int i=1;i<=len;i++)num+=s[i]-'0',nnum+=s[i]=='0',nnnum+=s[i]%2==0;
	puts(num%3==0&&nnum&&nnnum>1?"red":"cyan");
}
int main(){
	scanf("%d",&n);
	while(n--)solve();
}