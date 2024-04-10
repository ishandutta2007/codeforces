#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
set<string> s;
string str;
int m,tot;
int main()
{
	cin>>m;
	while (m--)
	{
		cin>>str;
		s.insert(str);
	}
	if (!s.count("purple")) tot++;
	if (!s.count("green")) tot++;
	if (!s.count("blue")) tot++;
	if (!s.count("orange")) tot++;
	if (!s.count("red")) tot++;
	if (!s.count("yellow")) tot++;
	printf("%d\n",tot);
	if (!s.count("purple")) puts("Power");
	if (!s.count("green")) puts("Time");
	if (!s.count("blue")) puts("Space");
	if (!s.count("orange")) puts("Soul");
	if (!s.count("red")) puts("Reality");
	if (!s.count("yellow")) puts("Mind");
	return 0;
}