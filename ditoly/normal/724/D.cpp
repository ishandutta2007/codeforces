#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXL 100000
vector<int> v[26];
char s[MAXL+5];
int c[MAXL+5];
inline int&C(int x){return c[x<0?0:x];}
int main()
{
	int m,i,j,k,l;
	scanf("%d%s",&m,s);
	for(i=0;s[i];i++)v[s[i]-'a'].push_back(i);
	for(i=0;;i++)
	{
		for(j=0;j<v[i].size();j++)C(v[i][j]-m+1)++,C(v[i][j]+1)--;
		for(j=0,k=0;s[j+m-1];j++){k+=c[j];if(!k)break;}
		if(!s[j+m-1])break;
		for(j=0;j<v[i].size();j++)putchar(i+'a');
	}
	for(j=0;j<v[i].size();j++)C(v[i][j]-m+1)--,C(v[i][j]+1)++;
	for(j=0,k=0;s[j+m-1];j++)
	{
		k+=c[j];
		if(!k)
		{
			for(l=j+m-1;s[l]!=i+'a';l--);
			putchar(i+'a');
			for(j++;s[j+m-1]&&j<=l;j++)k+=c[j];j--;
		}
	}
}