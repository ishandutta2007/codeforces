#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    int k;
    cin>>s>>k;
    ll n=atoi(s.c_str());
    if(n % ((ll)pow(10,k))==0)return 0*printf("0");
    int count = 0;
    for(int i= 0;i < s.length(); i++)
    {
    	if(s[i]=='0')count++;
	}
	int ans=0;
	if(count >= k)
	{
		int count_0 = 0;
		for(int i = s.length()-1; i>=0;--i)
		{
			if(s[i]=='0'){
				count_0++;
				if(count_0 == k)
				return 0*printf("%d\n",ans);
			}
			else ans++;
		}
	}
	cout<<s.length()-1<<endl;
    return 0;
}