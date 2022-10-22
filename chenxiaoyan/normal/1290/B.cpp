/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n;
char a[N+5];
int Sum[N+1][26];
int main(){
	cin>>a+1;
	n=strlen(a+1);
	for(int i=1;i<=n;i++)for(int j=0;j<26;j++)Sum[i][j]=Sum[i-1][j]+(a[i]=='a'+j);
	int qu;
	cin>>qu;
	while(qu--){
		int l,r;
		cin>>l>>r;
		int cnt=0;
		for(int i=0;i<26;i++)cnt+=!!(Sum[r][i]-Sum[l-1][i]);
		puts(l==r||cnt==2&&a[l]!=a[r]||cnt>2?"Yes":"No");
	}
	return 0;
}