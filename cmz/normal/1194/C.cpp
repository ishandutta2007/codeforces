#include<bits/stdc++.h>
using namespace std;
const int N=200;
int t,la,lb,lc,num[3][26];char a[N],b[N],c[N];bool flag;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s%s%s",a+1,b+1,c+1);flag=0;
		memset(num,0,sizeof(num));
		la=strlen(a+1);lb=strlen(b+1);lc=strlen(c+1);
		int j=1;
		for(int i=1;i<=lb;i++)if(j<=la&&b[i]==a[j])j++;
		if(j<=la){puts("NO");continue;}
		for(int i=1;i<=la;i++)num[0][a[i]-'a']++;
		for(int i=1;i<=lb;i++)num[1][b[i]-'a']++;
		for(int i=1;i<=lc;i++)num[2][c[i]-'a']++;
		for(int i=0;i<26;i++)if(num[0][i]+num[2][i]<num[1][i])flag=1;
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}