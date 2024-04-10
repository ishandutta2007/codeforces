/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=200000;
int n;
char a[N+5];
int Bal[N+1];
int main(){
	cin>>n>>a+1;
	for(int i=1;i<=n;i++)Bal[i]=a[i]=='('?Bal[i-1]+1:Bal[i-1]-1;
	if(Bal[n])return puts("NO"),0;
	bool ok=true;
	for(int i=1;i<=n;i++)ok&=Bal[i]>=0;
	if(ok)return puts("YES"),0;
	int lasn;
	for(int i=1;i<=n;i++)if(Bal[i]<0)lasn=i;
	int mn=inf;
	for(int i=1;i<=lasn;i++)mn=min(mn,Bal[i]);
	bool havl=false;
	for(int i=lasn+1;i<=n;i++)havl|=a[i]=='(';
	if(havl&&mn>=-1)return puts("YES"),0;
	puts("NO");
	return 0;
}