#include<bits/stdc++.h>
using namespace std;
const int LET=26;
string a,b,c;
int no[LET];
void insert(int x){
	a=a.substr(0,x)+b[x]+a.substr(x,a.size()-x);
}
void mian(){
	cin>>a>>b>>c;
	memset(no,0,sizeof(no));
	for(int i=0;i<c.size();i++)no[c[i]-'a']++;
	for(int i=0;i<b.size();i++)if(a.size()-1<i||a[i]!=b[i])
		if(no[b[i]-'a'])no[b[i]-'a']--,insert(i);
		else{puts("NO");return;}
	puts(a.size()==b.size()?"YES":"NO");
}
int main(){
	int qu;
	cin>>qu;
	while(qu--)mian();
	return 0;
}
/*1
4
ab
acxb
cax
a
aaaa
aaabbcc
a
aaaa
aabbcc
ab
baaa
aaaaa
*/