#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,k;

int f(string s)
{
	int l=0,r=-1;
	int num=0;
	int res=0;
	while(++r<s.size())
	{
		if(s[r]=='b')
			num++;
		if(num>k)
		{
			while(s[l++]=='a');
			num--;
		}
		res=max(res,r-l+1);
	}
	
	return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string s;
	cin>>n>>k;
	cin>>s;
	int ans=f(s);
	for(int i=0;i<s.size();i++)
		s[i]='a'+'b'-s[i];
	ans=max(ans,f(s));
	cout<<ans<<endl;
    return 0;
}