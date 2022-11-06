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
int n,a[200010],x,l,r,t,o;
set<int> S;
bool check(int o){
	S.clear();
	FOR(i,1,n){
		t=0;
		FORD(j,31,0){
			if (a[i]&(1ll<<j)) t=t*2+1; else t<<=1;
			if (t>o){t>>=1;break;}
		}
		while (S.find(t)!=S.end()) t/=2;
		if (t==0) return 0;
		S.insert(t);
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n) getint(a[i]);
	sort(a+1,a+n+1);
	l=0;
	r=1000000010;
	while (l<r){
		int o=(l+r)>>1;
		if (check(o)) r=o; else l=o+1;
	}
	check(r);
	while (!S.empty()){
		int x=*S.begin();
		S.erase(S.begin());
		if (S.empty()) printf("%d\n",x); else printf("%d ",x);
	}
	return 0;
}