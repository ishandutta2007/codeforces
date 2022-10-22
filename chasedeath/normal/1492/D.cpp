#include<bits/stdc++.h>
using namespace std;

int a,b,k;
char s[1000010];

int main() {
	scanf("%d%d%d",&a,&b,&k);
	if(a==0) {
		if(k) puts("No");
		else {
			puts("Yes");
			for(int i=1;i<=b;++i) putchar('1');
			puts("");
			for(int i=1;i<=b;++i) putchar('1');
		}
		return 0;
	}
	if(b==1) {
		if(k) puts("No");
		else {
			puts("Yes");
			putchar('1');
			for(int i=1;i<=a;++i) putchar('0');
			puts("");
			putchar('1');
			for(int i=1;i<=a;++i) putchar('0');
		}
		return 0;
	}
	if(k>a+b-2) return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=b;++i) s[i]='1';
	for(int i=b+1;i<=a+b;++i) s[i]='0';
	puts(s+1);
	if(k<=a) s[b]='0',s[b+k]='1';
	else {
		s[b]='0',s[a+b]='1';
		k-=a;
		for(int i=1;i<=k;++i) s[b-i]='0',s[b-i+1]='1';
	}
	puts(s+1);
}