#include<bits/stdc++.h>
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
const int maxn=25;
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
char s[maxn];
int main(){
	int x;read(x);scanf("%s",s+1);scanf("%s",s+1);
	if(s[1]=='w'){
		if(x==5||x==6){
			puts("53");
		}else
			puts("52");
	}
	else{
		if(x<=29){
			puts("12");return 0;
		}
		if(x==30){
			puts("11");return 0;
		}
		puts("7");
	}
	return 0;
}