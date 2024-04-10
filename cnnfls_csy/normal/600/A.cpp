#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int n,m,i,j,k;
string st,st1;
vector<string> num,word;
bool check(string st)
{
	int i;
	if (!st.length()) return 0; 
	for (i=0;i<st.length();i++) if (st[i]>'9'||st[i]<'0') return 0;
	if (st.length()==1) return 1; 
	if (st[0]=='0') return 0;
	return 1;
} 
int main()
{
	getline(cin,st);
	i=0;
	while (i<st.length())
	{
		st1="";
		while (i<st.length()&&st[i]!=';'&&st[i]!=',')
		{
			st1.push_back(st[i]);
			i++;
		}
		if (check(st1))
		{
			num.push_back(st1);
		}
		else
		{
			word.push_back(st1);
		}
		i++;
	}
	if (st[st.length()-1]==';'||st[st.length()-1]==',') word.push_back("");
	if (num.empty()) cout<<"-"<<endl;
	else
	{
		cout<<'"';
		for (i=0;i<num.size()-1;i++) cout<<num[i]<<',';
		cout<<num[num.size()-1]<<'"'<<endl;
	}
	if (word.empty()) cout<<"-"<<endl;
	else
	{
		cout<<'"';
		for (i=0;i<word.size()-1;i++) cout<<word[i]<<',';
		cout<<word[word.size()-1]<<'"'<<endl;
	}
	return 0;
}