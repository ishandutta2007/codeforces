#include<bits/stdc++.h>
using namespace std;
#define re register int
inline int check(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return 1;
	else return 0;
}
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.length()!=b.length()) return puts("No"),0;
	for(re i=0;i<a.length();i++)
	if(check(a[i])!=check(b[i])) return puts("No"),0;
	return puts("Yes"),0;
}