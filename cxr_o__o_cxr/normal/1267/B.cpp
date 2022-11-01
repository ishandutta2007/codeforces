//starusc
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+4;
char c[N];
int n,b[N],col[N],cnt=0;
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]){
			cnt++;
			col[cnt]=c[i]-'A'+1;
		}
		b[cnt]++;
	}
	if(cnt%2==0||b[cnt+1>>1]<2){cout<<0;return (0-0);}
	for(int u=(cnt>>1),v=(cnt>>1)+2;u>=1,v<=cnt;u--,v++)
		if(col[u]!=col[v]||b[u]+b[v]<3){cout<<0;return (0-0);} 
	cout<<b[(cnt+1)>>1]+1;
	return (0-0);
}