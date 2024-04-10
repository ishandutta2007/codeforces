#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

char S[10][33]=
{
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};
char s[10][33];
int main()
{
	int k;
	cin>>k;
	for(int i=1;i<=22&&k;i++)
		for(int j=1;j<=4&&k;j++)
			if(S[j][i]=='#')
				S[j][i]='O',k--;
	for(int i=0;i<6;i++)
		puts(S[i]);
	return 0;
}