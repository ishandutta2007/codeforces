#include<stdio.h>
#include<iostream>
using namespace std;
#define R register int
int v[26];
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length();
	R i=0,j=1;
	while(i<l){
		while(j<l&&s[i]==s[j]){
			j++;
		}
		int x=s[i]-'a';
		if(v[x]%2==0){
			if((j-i)%2==1){
				v[x]=1;
			}
		}
		i=j;
		j++;
	}
	for(i=0;i<26;i++){
		if(v[i]==1){
			printf("%c",i+'a');
		}
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
		for(R j=0;j<26;j++){
			v[j]=0;
		}
	}
	return 0;
}