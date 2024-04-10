#include<bits/stdc++.h>
using namespace std;
//string s[12]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
int num[1010];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&num[i]);
	}
	int l=0,r=0;
	bool sign=true;
	for(i=1;i<=n;++i){
		if(num[i]!=i)break;
	}
	l=i;
	if(i>n)sign=false;
	for(j=i+1;j<=n;++j){
		if(num[j]-num[j-1]!=-1){
			break;
		}
	}
	r=j-1;
	for(i=j;i<=n;++i){
		if(num[i]!=i){
			sign=false;break;
		}
	}
	if(r<l)sign=false;
	if(sign){
		printf("%d %d\n",l,r);
	}
	else
	{
		printf("0 0\n");
	}
    return 0;
}