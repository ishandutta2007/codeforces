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
string a[1010];
bool ok;
int main()
{
	scanf("%d",&n);
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n)
		if (a[i][0]==a[i][1] && a[i][0]=='O'){
			ok=1;
			a[i][0]=a[i][1]='+';
			break;
		}
		else if (a[i][3]==a[i][4] && a[i][3]=='O'){
			ok=1;
			a[i][3]=a[i][4]='+';
			break;
		}
	if (!ok) puts("NO");
	else{
		puts("YES");
		FOR(i,1,n) cout<<a[i]<<endl;
	}
	return 0;
}