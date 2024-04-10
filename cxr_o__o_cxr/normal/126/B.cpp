#include<bits/stdc++.h>
using namespace std;
const int N=1e6+4;
int n,fail[N],z[N];
char s[N];
inline void Z_algorithm(){
	for(int i=2,l=1,r=1,k;i<=n;i++){
		if(i>r){
			l=r=i;
			while(r<=n&&s[r-l+1]==s[r])r++;
			z[i]=r-l;r--;
		}
		else{
			k=i-l+1;
			if(z[k]<r-i+1)z[i]=z[k];
			else{
				l=i;
				while(r<=n&&s[r-l+1]==s[r])r++;
				z[i]=r-l;r--;
			}
		}
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	Z_algorithm();
	int mx=0,pos=0;
	for(int i=2;i<=n;i++){
		if(z[i]==n-i+1&&mx>=n-i+1){pos=i;break;}// 
		mx=max(mx,z[i]);
	}
	if(!pos)printf("Just a legend");
	else for(int i=1;i<=n-pos+1;i++)putchar(s[i]);
	return (0-0);
}