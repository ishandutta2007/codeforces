#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=105;
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

char a[maxn];
int main(){
 //   judge();
	scanf("%s",a+1);int n=strlen(a+1);
	fortodo(i,1,n) if (a[i]=='0'){
		puts("YES\n0");return 0;
	}
	fortodo(i,1,n) fortodo(j,i,n) fortodo(k,j,n){
		int step;
		if ((i==j)&&(j==k)){
			step=a[i]-'0';if (step%8==0){
				printf("YES\n%d",step);return 0;
			}
			continue;
		}
		if (i==j){
			step=(a[i]-'0')*10+a[k]-'0';
			if (step%8==0){
				printf("YES\n%d",step);return 0;
			}
			continue;
		}
		if (j==k){
			step=(a[i]-'0')*10+a[k]-'0';
			if (step%8==0){
				printf("YES\n%d",step);return 0;
			}
			continue;
		}
		step=(a[i]-'0')*100+(a[j]-'0')*10+a[k]-'0';			
		if (step%8==0){
				printf("YES\n%d",step);return 0;
			}
		}
	puts("NO");
    return 0;
}