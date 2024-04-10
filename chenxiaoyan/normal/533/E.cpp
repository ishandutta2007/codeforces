#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
char a[N+5],b[N+5];
int main(){
	cin>>n>>a+1>>b+1;
	int fst,las;
	for(int i=1;;i++)if(a[i]!=b[i]){fst=i;break;}
	for(int i=n;;i--)if(a[i]!=b[i]){las=i;break;}
	if(fst==las)return puts("2"),0;
	int ans=0;
	bool ok=true;
	for(int i=fst;i<las;i++)if(a[i]!=b[i+1]){ok=false;break;}
	ans+=ok;
	ok=true;
	for(int i=fst;i<las;i++)if(b[i]!=a[i+1]){ok=false;break;}
	ans+=ok;
	printf("%d",ans);
	return 0;
}
/*1
7
reading
trading
*/
/*2
5
sweet
sheep
*/
/*3
3
toy
try
*/