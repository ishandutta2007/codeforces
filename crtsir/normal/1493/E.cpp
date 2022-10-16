#include<bits/stdc++.h>
using namespace std;
int n;
char S[1000003],T[1000003],s[1000003],t[1000003],ans[1000003],ret[1000003];
bool check(){int i=0;
	for(i=0;i<n;i++)
		if(s[i]!=t[i])
			break;
	if(s[i]=='1'||t[i]=='0')return 0;i++;
	for(;i<n;i++)
		if(s[i]=='0'||t[i]=='1')
			return 0;
	return 1;
}
bool equ(){
	for(int i=0;i<n;i++)
		if(s[i]!=t[i])
			return 0;
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){S[i]=getchar();if(S[i]!='0'&&S[i]!='1')i--;}
	for(int i=0;i<n;i++){T[i]=getchar();if(T[i]!='0'&&T[i]!='1')i--;}
	int k=0;
	while(k<n&&S[k]=='0'&&T[k]=='0')k++;
	for(int i=k;i<n;i++)s[i-k]=S[i],t[i-k]=T[i];
	n=n-k;
	if(n==0){cout<<0;return 0;}
	if(equ()){cout<<t;return 0;}
	if(s[0]!=t[0]){
		for(int i=0;i<n;i++)
			putchar('1');
		return 0;
	}
	for(int i=0;i<n;i++)ans[i]=t[i];
	for(int i=0;i<n;i++){
		if(s[i]==t[i])continue;
		//T or T (T-1) (T-2) 
		if(ans[n-1]=='0'&&!check())
			ans[n-1]='1';
		for(int i=0;i<n;i++)
			putchar(ans[i]);
		return 0;
	}
}