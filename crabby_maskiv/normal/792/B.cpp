#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int n,k;
int a[105];
int main()
{
	cin>>n>>k;
	int i;
	for(i=1;i<=n;i++) q.push(i);
	for(i=0;i<k;i++) cin>>a[i];
	for(i=0;i<k;i++)
	{
		a[i]%=q.size();
		while(a[i]--)
		{
			q.push(q.front());
		    q.pop();
		}
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}