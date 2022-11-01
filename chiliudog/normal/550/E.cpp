#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1000005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int a[maxn],n,cnt;
char s[maxn];
int main(){
 //   judge();
	read(n);
	fortodo(i,1,n) read(a[i]);
	if (a[n]==1){
		puts("NO");return 0;
	}
	if (n==1){
		puts("YES\n0");return 0;
	}
	if (a[n-1]==1){
	   printf("YES\n");	fortodo(i,1,n-1) printf("%d->",a[i]);printf("%d",a[n]);return 0;
	}
	int place;
	for(place=n-2;place>=1;place--) if (a[place]==0) break;
	if (place==0){
		puts("NO");return 0;
	}
	puts("YES");
	fortodo(i,1,place-1) printf("%d->",a[i]);putchar('(');printf("%d->",a[place]);printf("(");
	fortodo(i,place+1,n-2) printf("%d->",a[i]);printf("%d",a[n-1]);putchar(')');putchar(')');
	printf("->%d",a[n]);
    return 0;
}