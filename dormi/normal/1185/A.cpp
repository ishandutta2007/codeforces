#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a,b,c,d;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	lli fircnt=0;
	fircnt+=max((lli)0,d-(b-a));
	fircnt+=max((lli)0,d-(c-b));
	printf("%lli\n",fircnt);
	return 0;
}