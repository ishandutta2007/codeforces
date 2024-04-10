#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define TP int
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int n,m;
int x[1010],y[1010];
char MMM[1010][1010];
signed main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
    	scanf("%s",MMM[i]+1);
    	for(int j=1;j<=m;j++)
    		if(MMM[i][j]=='*')
    			x[i]++,y[j]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		if(MMM[i][j]=='*')
    			ans+=(x[i]-1)*(y[j]-1);
    cout<<ans;
}