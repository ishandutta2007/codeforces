#include<iostream>
using namespace std;
string s="Bulbasaur",S;
int a[256];
int main()
{
	int i,j;
	cin>>S;
	for(i=0;S[i];++i)++a[S[i]];
	for(i=0;;++i)
	{
		for(j=0;s[j];++j)if(!a[s[j]])break;else --a[s[j]];
		if(s[j])break;
	}
	cout<<i;
}