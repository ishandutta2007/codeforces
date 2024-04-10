#include <iostream>

int k;
char q[100];
int istr[27];
bool check[256];

void main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::cin>>k;
	std::cin>>q;
	int len = strlen(q);
	memset(check, 0, 256);
	memset(istr, 0, 27);
	int n = 0;
	int index = 0;
	while (n < k)
	{
		if (n == 0)
		{
			check[q[0]] = true;
			n++;
			continue;
		}
		for (int i = index + 1; i < len; i++)
		{
			if (!check[q[i]])
			{
				istr[n] = i;
				check[q[i]] = true;
				break;
			}
		}
		if (istr[n] == 0)
		{
			std::cout<<"NO";
			return;
		}
		n++;
	}
	std::cout<<"YES";
	istr[k] = len;
	for (int i = 0; i < k; i++)
	{
		char buf = q[istr[i + 1]];
		q[istr[i + 1]] = 0;
		std::cout<<"\n"<<q + istr[i];
		q[istr[i + 1]] = buf;
	}
}