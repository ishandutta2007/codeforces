/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,a,b,c;
char s[N+5],t[N+5];
void mian(){
	cin>>n>>a>>b>>c>>s+1;
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)
		if(a&&s[i]=='S')a--,t[i]='R';
		else if(b&&s[i]=='R')b--,t[i]='P';
		else if(c&&s[i]=='P')c--,t[i]='S';
	if(n-a-b-c<n+1>>1)puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n;i++)if(!t[i])
			if(a)a--,t[i]='R';
			else if(b)b--,t[i]='P';
			else if(c)c--,t[i]='S';
		puts(t+1);
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}