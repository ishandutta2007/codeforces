#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int num[26];
bool is_prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
char c[1002];
int main()
{
	cin>>s;
	n=s.size()-1;
	for(int i=2;i<=s.size();i++)
		if(i*2>s.size())
			n-=is_prime(i);
	for(int i=0;i<s.size();i++)
		num[s[i]-'a']++;
	int let;
	bool ok=false;
	for(int i=0;i<26;i++)
		if(num[i]>=n)
			ok=true,
			let=i;
	if(!ok)
	{
		cout<<"NO";
		return 0;
	}
	else
	cout<<"YES"<<endl;
	int js=0;
	num[let]=num[let]-n;
	for(int i=1;i<=s.size();i++)
		if(i==1||(i*2>s.size()&&is_prime(i)))
		{
			while(!num[js])js++;
			cout<<char(js+'a');
			num[js]--;
		}
		else
			cout<<char(let+'a');
	printf("%s",c);
}