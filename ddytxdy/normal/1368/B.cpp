#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL k;int len,pp;
string s="codeforces";
int main(){
	cin>>k;
	for(len=1;;len++){
		long double p=1;
		for(int i=1;i<=10;i++)p*=len;
		if(p>k+100)break;
		long long q=1;
		for(int i=1;i<=10;i++)q*=len;
		if(q>=k)break;
	}
	for(pp=1;pp<=10;pp++){
		long double p=1;
		for(int i=1;i<=pp;i++)p*=len;
		for(int i=pp+1;i<=10;i++)p*=len-1;
		if(p>k+100)break;
		long long q=1;
		for(int i=1;i<=pp;i++)q*=len;
		for(int i=pp+1;i<=10;i++)q*=len-1;
		if(q>=k)break;
	}
	for(int i=1;i<=pp;i++)
		for(int j=1;j<=len;j++)putchar(s[i-1]);
	for(int i=pp+1;i<=10;i++)
		for(int j=1;j<=len-1;j++)putchar(s[i-1]);
	return 0;
}