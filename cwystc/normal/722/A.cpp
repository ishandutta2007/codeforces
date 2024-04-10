#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
void putint(LL n)
{
     char a[20];
     int size=0;
     if (n==0)
        putchar('0');
     while (n)
     {
           a[size++]=n%10+48;
           n/=10;
     }
     for (int i=size-1;i>=0;i--)
         putchar(a[i]);
     putchar('\n');
}
int n;
char s[9999];
int main()
{
	scanf("%d%s",&n,s);
	if (n==24){
		int t=(s[0]-48)*10+s[1]-48;
		if (t<0 || t>23) s[0]='0';
		t=(s[3]-48)*10+s[4]-48;
		if (t<0 || t>59) s[3]='0';
	}
	else{
		int t=(s[0]-48)*10+s[1]-48;
		if (t==0) s[0]='1';
		else if (t>12){
			if (s[1]=='0') s[0]='1'; else s[0]='0';
		}
		t=(s[3]-48)*10+s[4]-48;
		if (t<0 || t>59) s[3]='0';
	}
	int m=strlen(s);
	FOR(i,0,m-1) putchar(s[i]);
	return 0;
}