#include <bits/stdc++.h>  
using namespace std;    
int main()  
{
	string s; 
	cin>>s;
	int b=32;
	for(int i=1;i<s.size();i++) 
		if(s[i]>='a')b=0; 
	for(int i=0;s[i];i++)
		putchar(b^s[i]);
	return 0;
}