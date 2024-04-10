#include<iostream>
#include<stack>
using namespace std;
bool h[1005];
int a[55],cnt;
stack<int> s;
int main()
{
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=n-1;i>=0;i--)
	{
		if(h[a[i]]==0)
		{
			cnt++;
			h[a[i]]=1;
			s.push(a[i]);
		}
	}
	cout<<cnt<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}