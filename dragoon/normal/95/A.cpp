#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

char word[104][104],line[104],like[3];
string w[104], L;

int cmp(string a, string b)
{
	int i;
	for(i=0;i<a.length();i++)
		if(tolower(a[i])!=tolower(b[i]))
			return 0;
		return 1;
}

int main()
{
	string ans;
	int j, k;
	int n, i;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",word[i]);
		w[i] = word[i];
	}

	scanf("%s%s",line,like);
	L = line;
	if(like[0]>='a' && like[0]<='z')
		like[0]=like[0]-'a'+'A';

	for(i='A';;i++)
	if(like[0]!=i)
		break;
	like[1]=i;	

	ans = L;
	int lenL = strlen(line);
	for(i=0;i<lenL;i++)
		for(j=0;j<n;j++)
		{
			if(i+w[j].length()<=lenL && cmp(L.substr(i,w[j].length()),w[j]))
			{
				for(k=0;k<w[j].length();k++)
					if(toupper(L[k+i])!=like[0])
					{
						if(ans[k+i]>='a' && ans[k+i]<='z')
							ans[k+i] = like[0]-'A'+'a';
						else
							ans[k+i] = like[0];
					}
					else
					{
						if(ans[k+i]>='a' && ans[k+i]<='z')
							ans[k+i] = like[1]-'A'+'a';
						else
							ans[k+i] = like[1];
					}
			}
		}

	printf("%s\n",ans.c_str());


	return 0;
}