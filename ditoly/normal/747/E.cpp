#include<iostream>
using namespace std;
#define MN 1000000
string s,ans[MN+5];
int f[MN+5];
int main()
{
	int i,l=1,mx=1;
	cin>>s;f[0]=0x7fffffff;
	for(i=0;i<s.size();++i)
	{
		while(!f[l-1]--)--l;if(l>mx)mx=l;
		for(;s[i]!=',';++i)ans[l]+=s[i];
		ans[l]+=' ';f[l]=0;
		for(++i;i<s.size()&&s[i]!=',';++i)f[l]=f[l]*10+s[i]-'0';
		++l;
	}
	cout<<mx<<endl;
	for(i=1;i<=mx;++i)cout<<ans[i]<<endl;
}