#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=100005;
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

char s[maxn];
int main(){
 //   judge();
	scanf("%s",s+1);int n=strlen(s+1);
	fortodo(i,1,n-1){
		if ((s[i]=='A')&&(s[i+1]=='B')){
			int place=0;
			fortodo(j,i+2,n-1){
				if (s[j]=='B'&&s[j+1]=='A') place=j;
			}
			if (place){
				puts("YES");return 0;
			}
			if (s[i+2]=='A'){
				fortodo(j,i+3,n-1){
					if (s[j]=='A'&&s[j+1]=='B') place=j;
				}
				if (place){
					puts("YES");return 0;
				}
				else{
					puts("NO");return 0;
				}
			}
			puts("NO");return 0;
		}		
		if ((s[i]=='B')&&(s[i+1]=='A')){
			int place=0;
			fortodo(j,i+2,n-1){
				if (s[j]=='A'&&s[j+1]=='B') place=j;
			}
			if (place){
				puts("YES");return 0;
			}
			if (s[i+2]=='B'){
				fortodo(j,i+3,n-1){
					if (s[j]=='B'&&s[j+1]=='A') place=j;
				}
				if (place){
					puts("YES");return 0;
				}
				else{
					puts("NO");return 0;
				}
			}
			puts("NO");return 0;
		}
	}
	puts("NO");
    return 0;
}