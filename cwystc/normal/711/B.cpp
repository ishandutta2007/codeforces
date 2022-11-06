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

int n,l,c;
LL s,t,a[555][555],ans;
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)
		FOR(j,1,n)
		{
			cin>>a[i][j];
			if (a[i][j]==0) l=i,c=j;
		}
	if (n==1){
		puts("1"); return 0;
	}
	FOR(i,1,n){
		s=0;
		if (l==i) continue;
		FOR(j,1,n) s+=a[i][j];
		break;
	}
	FOR(i,1,n){
		t=0;
		if (l==i){
			FOR(j,1,n) t+=a[i][j];
			ans=a[i][c]=s-t;
			if (a[i][c]<1 || a[i][c]>1e18) return puts("-1"),0;
		}
		else{
			FOR(j,1,n) t+=a[i][j];
			if (t!=s) return puts("-1"),0;
		}
	}
	FOR(j,1,n){
		t=0;
		FOR(i,1,n) t+=a[i][j];
		if (t!=s) return puts("-1"),0;
	}
	t=0;
	FOR(i,1,n) t+=a[i][i];
	if (t!=s) return puts("-1"),0;
	t=0;
	FOR(i,1,n) t+=a[n-i+1][i];
	if (t!=s) return puts("-1"),0;
	cout<<ans<<endl;
	return 0;
}