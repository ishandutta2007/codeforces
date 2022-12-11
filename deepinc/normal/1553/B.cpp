#include<bits/stdc++.h>
using namespace std;
char s[555],t[1111];
#define ull unsigned long long
ull hsh[555],hsht[1111],pw[1111],ihsh[555];
ull H(ull*s,int l,int r){return s[r]-s[l-1]*pw[r-l+1];}
ull iH(int l,int r){return ihsh[l]-ihsh[r+1]*pw[r-l+1];}
int main(){
	for(int i=pw[0]=1;i<=1000;++i)pw[i]=pw[i-1]*233;
	int T;cin>>T;while(T--){
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1),lt=strlen(t+1);
		for(int i=1;i<=ls;++i)hsh[i]=hsh[i-1]*233+s[i]-'a';
		for(int i=1;i<=lt;++i)hsht[i]=hsht[i-1]*233+t[i]-'a';
		ihsh[ls+1]=0;
		for(int i=ls;i;--i)ihsh[i]=ihsh[i+1]*233+s[i]-'a';
		for(int p=1;p<=ls;++p)for(int len=1;len<=lt&&p+len-1<=ls;++len)if(p-2+len-lt+len+1>=1)
			if(H(hsh,p,p-1+len)==H(hsht,1,len)&&H(hsht,len+1,lt)==iH(p-2+len-lt+len+1,p-2+len))
				{puts("Yes");goto Y;}
		puts("No");Y:;
	}
}