#include<bits/stdc++.h>
int t,n,x;
char s[100001],w[100001];bool f;
int main(){scanf("%d",&t);
	for(;t--;){
		scanf("%s%d",s,&x);
		n=strlen(s);
		for(int i=0;i<n;++i)w[i]='1';w[n]=0;f=0;
		for(int i=0;i<n;++i)if(s[i]=='0'){
			if(i-x>=0)w[i-x]='0';
			if(i+x<n)w[i+x]='0';
		}
		for(register int i=0;i<n;++i)
			if(s[i]=='1'&&(i-x<0||w[i-x]=='0')&&(i+x>=n||w[i+x]=='0'))f=1;
		if(f)puts("-1");
		else printf("%s\n",w);
	}
}