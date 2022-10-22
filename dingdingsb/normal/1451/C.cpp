#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[26],b[26];
char s[1000000+10];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=0;i<26;i++)a[i]=0;
		for(int i=1;i<=n;i++)a[s[i]-'a']++;
		scanf("%s",s+1);
		for(int i=0;i<26;i++)b[i]=0;
		for(int i=1;i<=n;i++)b[s[i]-'a']++;
		for(int i=0;i<26;i++){
			if(a[i]<b[i]){puts("No");goto loop;}
			while(a[i]-k>=b[i])a[i]-=k,a[i+1]+=k;
		}
		puts("Yes");
		loop:; 
	}
	return 0;
}