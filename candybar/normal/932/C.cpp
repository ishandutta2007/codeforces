#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n,a,b;

inline int input(){
  int x=0;
  char c;
  for (c=getchar();c<'0' || c>'9';c=getchar());
  for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
  return x;
}

inline void output(int x){
  if (!x) putchar('0');
	else{
    char s[10];
    int i,j=0;
    for (;x>0;x/=10) s[j++]=x%10;
    for (i=j-1;i>=0;i--) putchar(s[i]+48);
  }
  putchar(' ');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	n = input();
	a = input();
	b = input();
	bool fl = 0;
	int x,y;
	for(int i=0;i*a<=n;i++){
		if((n - i * a) % b == 0){
			fl = 1;
			x = i;
			y = (n - i * a)/b;
			break;
		}
	}
	if(!fl){
		puts("-1");
		return 0;
	}
	int cur = 0;
	for(int i=1;i<=x;i++){
		output(cur + a);
		for(int j=2;j<=a;j++){
			output(cur + j - 1);
		}
		cur += a;
	}
	for(int i=1;i<=y;i++){
		output(cur + b);
		for(int j=2;j<=b;j++){
			output(cur + j - 1);
		}
		cur += b;
	}
	printf("\n");
	return 0;
}