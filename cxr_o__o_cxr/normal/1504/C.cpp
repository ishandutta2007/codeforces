//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
int n,c[2],ans1[N],ans2[N];
char s[N];
inline void solve(){
	n=read();
	scanf("%s",s+1);
	if(s[1]=='0'||s[n]=='0'){puts("NO");return;}
	c[0]=c[1]=0;
	for(int i=1;i<=n;i++){
		c[s[i]-'0']++;
	}
//	cerr<<c[0]<<" "<<c[1]<<"\n";
	if((c[1]&1)||(c[0]&1)){puts("NO");return;}
	c[1]>>=1;
	for(int i=1,s1=0,s2=0;i<=n;i++){
		if(s[i]=='1'){
			if(c[1]){ans1[i]=ans2[i]=1;c[1]--;s1++;s2++;}
			else{
				ans1[i]=ans2[i]=0;
				if(!s1||!s2){puts("NO");return;}
				s1--;s2--;
			}
		}
		else{
			if(s1<s2){
				if(!s2){puts("NO");return;}
				ans1[i]=1;ans2[i]=0;
				s2--;s1++;
			}
			else{
				if(!s1){puts("NO");return;}
				ans1[i]=0;ans2[i]=1;
				s1--;s2++;
			}
		}
//		cerr<<s1<<" "<<s2<<"\n";
	}
	puts("YES");
	for(int i=1;i<=n;i++)putchar(ans1[i]?'(':')');puts("");
	for(int i=1;i<=n;i++)putchar(ans2[i]?'(':')');puts("");
}
int main(){
	for(int T=read();T--;)solve();
	return (0-0);
}