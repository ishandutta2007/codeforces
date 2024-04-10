#include <iostream>
using namespace std;
const int inf=1e9;
int ans=inf;
void solve(string s,string p)
{
	int cnt=0,t1=s.rfind(p[1]),t2,z=0,z1=0;
	if (p[0]==p[1]) t2=s.rfind(p[0],t1-1);
	else t2=s.rfind(p[0]);
	for (auto x:s) if (x!='0') break;
	if (t1==-1 || t2==-1) return;
	for (int i=t1;i<s.size()-1;i++)
	{
		swap(s[i],s[i+1]);
		cnt++;
	}
	t2=s.rfind(p[0],s.size()-2);
	for (int i=t2;i<s.size()-2;i++)
	{
		swap(s[i],s[i+1]);
		cnt++;
	}
	for (auto &x:s)
	{
		if (x!='0') break;
		z1++;
	}
	if (s.size()-2>=2*z1) ans=min(ans,cnt+z1);
}
int main()
{
	string s;
	cin>>s;
	for (string t:{"00","25","50","75"}) solve(s,t);
	cout<<((ans==inf)?-1:ans)<<"\n";
	return 0;
}