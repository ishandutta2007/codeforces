#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define R register int
char s[100001];
int ct[26];
inline void Print(const char c,const int n){
	for(R i=0;i!=n;i++){
		putchar(c);
	}
}
inline void Solve(){
	scanf("%s",s);
	int n=strlen(s),z=0;
	for(R i=0;i!=26;i++){
		ct[i]=0;
	}
	for(R i=0;i!=n;i++){
		ct[s[i]-'a']++;
	}
	for(R i=0;i!=26;i++){
		if(ct[i]==0){
			z++;
		}
	}
	if(z==25){
		puts(s);
		return;
	}
	z=-1;
	for(R i=0;i!=26;i++){
		if(ct[i]==1){
			putchar(i+'a');
			for(R j=0;j!=26;j++){
				if(i!=j){
					Print(j+'a',ct[j]);
				}
			}
			puts("");
			return;
		}
		if(ct[i]!=0&&z==-1){
			z=i;
		}
	}
	if(ct[z]-1<=n>>1){
		Print(z+'a',2);
		ct[z]-=2;
		string s;
		for(R i=z+1;i!=26;i++){
			for(R j=ct[i];j!=0;j--){
				s+=i+'a';
			}
		}
		int cur=0;
		for(R i=ct[z];i!=0;i--){
			putchar(s[cur]);
			cur++;
			putchar(z+'a');
		}
		z=s.length();
		for(R i=cur;i!=z;i++){
			putchar(s[i]);
		}
		puts("");
		return;
	}
	int b=0,c=0;
	for(R i=z+1;i!=26;i++){
		if(ct[i]!=0){
			if(b==0){
				b=i;
			}else if(c==0){
				c=i;
			}
		}
	}
	putchar(z+'a');
	if(c==0){
		Print(b+'a',ct[b]);
		Print(z+'a',ct[z]-1);
	}else{
		putchar(b+'a');
		ct[b]--;
		Print(z+'a',ct[z]-1);
		putchar(c+'a');
		ct[c]--;
		for(R i=b;i!=26;i++){
			Print(i+'a',ct[i]);
		}
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}