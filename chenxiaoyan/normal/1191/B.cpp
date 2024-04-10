#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
char a1,a2,a3,b1,b2,b3;
pair<char,char> s[4];
int main(){
	scanf("%c%c %c%c %c%c",&a1,&b1,&a2,&b2,&a3,&b3);
//	cout<<a1<<b1<<a2<<b2<<a3<<b3<<"\n";
	if(a1==a2&&a1==a3&&b1==b2&&b1==b3)return printf("0"),0;
	s[1]=mp(a1,b1);s[2]=mp(a2,b2);s[3]=mp(a3,b3);
	sort(s+1,s+4);
//	for(int i=1;i<=3;i++)cout<<s[i].X<<s[i].Y;
	if(s[1].X==s[2].X-1&&s[2].X==s[3].X-1&&s[1].Y==s[2].Y&&s[1].Y==s[3].Y)return printf("0")
	,0;
	if(s[1].X==s[2].X&&s[1].Y==s[2].Y||s[2].X==s[3].X&&s[2].Y==s[3].Y||s[1].X==s[3].X&&s[1].
	Y==s[3].Y)return printf("1"),0;
	if(s[1].X==s[2].X-1&&s[1].Y==s[2].Y||s[2].X==s[3].X-1&&s[2].Y==s[3].Y||s[1].X==s[3].X-1
	&&s[1].Y==s[3].Y||s[1].X==s[2].X-2&&s[1].Y==s[2].Y||s[2].X==s[3].X-2&&s[2].Y==s[3].Y||s[
	1].X==s[3].X-2&&s[1].Y==s[3].Y)return printf("1"),0;
	printf("2");
	return 0;
}
/*1
1s 2s 3s
*/
/*2
9m 9m 9m
*/
/*3
3p 9m 2p
*/