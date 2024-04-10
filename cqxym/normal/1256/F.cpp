#include<stdio.h>
#define R register int
int ct1[26],ct2[26];
char s[200001],t[200001];
inline void Read(char *S,int n){
	getchar();
	for(R i=0;i<n;i++){
		S[i]=getchar();
	}
}
inline int Get(char *S,int n){
	int s=0;
	for(R i=1;i<n;i++){
		for(R j=0;j<i;j++){
			if(S[i]>S[j]){
				s++;
			}
		}
	}
	return s;
}
inline void Solve(){
	int n;
	for(R i=0;i<26;i++){
		ct1[i]=ct2[i]=0;
	}
	scanf("%d",&n);
	Read(s,n);
	Read(t,n);
	for(R i=0;i<n;i++){
		ct1[s[i]-'a']++;
		ct2[t[i]-'a']++;
	}
	bool f=false;
	for(R i=0;i<26;i++){
		if(ct1[i]!=ct2[i]){
			puts("NO");
			return;
		}else if(ct1[i]>1){
			f=true;
		}
	}
	if(f==true){
		puts("YES");
		return;
	}
	if((Get(s,n)+Get(t,n)&1)>0){
		puts("NO");
	}else{
		puts("YES");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}