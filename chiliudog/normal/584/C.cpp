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
char s1[maxn],s2[maxn],ans[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int n,m;
int main(){
 //   judge();
	read(n);read(m);int tot=0;
	scanf("%s",s1+1);scanf("%s",s2+1);
	fortodo(i,1,n)if (s1[i]==s2[i])tot++;
	if (m<(n-tot+1)/2){
		puts("-1");return 0;
	}
	int samediff=max(0,m-(n-tot));
	m-=samediff;
	int diffe=n-tot,two,one;
	if (m!=diffe){
		two=diffe-m;one=diffe-2*two;
	}
	else
		one=m;
	int last=1;
	fortodo(i,1,n)
		if (s1[i]==s2[i]){
			if (samediff){
				ans[i]=s1[i]+1;
				if (ans[i]>'z')ans[i]='a';
				samediff--;
			}
			else ans[i]=s1[i];
		}
		else{
			if (one){
				ans[i]=s1[i]+1;
				if (ans[i]==s2[i])ans[i]++;
				if (ans[i]>'z')ans[i]='a';
				if (ans[i]==s2[i])ans[i]++;
				one--;
			}
			else{
				last=1-last;
				if (last==0)
					ans[i]=s1[i];
				else
					ans[i]=s2[i];
				if (last==1)two--;
			}
		}
	puts(ans+1);
    return 0;
}