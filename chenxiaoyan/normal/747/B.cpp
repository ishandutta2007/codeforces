#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int main()
{
	map<char,int> no;
	int n,i;
	string dna;
	cin>>n>>dna;
	if(n%4)
	{
		cout<<"===";
		return 0;
	}
	int sho=n/4;
	for(i=0;i<n;i++)
		no[dna[i]]++;
	for(i=0;i<n;i++)
	{
		if(dna[i]!='?')
		{
			if(no[dna[i]]>sho)
			{
				cout<<"===";
				return 0;
			}
			continue;
		}
		if(no['A']<sho)
		{
			dna[i]='A';
			no['A']++;
			continue;
		}
		if(no['G']<sho)
		{
			dna[i]='G';
			no['G']++;
			continue;
		}
		if(no['C']<sho)
		{
			dna[i]='C';
			no['C']++;
			continue;
		}
		dna[i]='T';
		no['T']++;
	}
	cout<<dna;
	return 0;
}
/*1
8
AG?C??CT
*/
/*2
4
AGCT
*/
/*3
6
????G?
*/
/*4
4
AA??
*/