#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,a,b,c;
int main(){
	cin>>a>>b>>c;
	b--;n=a+b;
	if((!a) || (!b)){
		if(!c){
			puts("Yes");
			for(int i=1;i<=n+1;i++)printf("%d",(!a||i==1)?1:0);puts("");
			for(int i=1;i<=n+1;i++)printf("%d",(!a||i==1)?1:0);
		}else puts("No");
		return 0;
	}else{
		if(c>n-1)puts("No");
		else if(!c){
			puts("Yes");
			for(i=0;i<=b;i++)printf("1");
			for(i=1;i<=a;i++)printf("0");puts("");
			for(i=0;i<=b;i++)printf("1");
			for(i=1;i<=a;i++)printf("0");
		}else{
			b--;
			puts("Yes");
			int d1=b,d2=b;
			for(int i=0;i<=n;i++){
				if(i==0)printf("1");
				else if(i==n-c)printf("1");
				else if(i==n)printf("0");
				else if(d1)printf("1"),d1--;
				else printf("0");
			}puts("");
			for(int i=0;i<=n;i++){
				if(i==0)printf("1");
				else if(i==n-c)printf("0");
				else if(i==n)printf("1");
				else if(d2)printf("1"),d2--;
				else printf("0");
			}
		}
	}
	return 0;
}