#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	stack<int> s;
	vector<int> l(n+1,0),r(n+1,n+1);
	for(int i=1;i<=n;i++)
    {
        while((!s.empty())&&a[s.top()]>=a[i]) s.pop();
        if(s.empty()) l[i]=0;
        else l[i]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while((!s.empty())&&a[s.top()]>=a[i]) s.pop();
        if(s.empty()) r[i]=n+1;
        else r[i]=s.top();
        s.push(i);
    }
    vector<int> best(n+1,0);
    for(int i=1;i<=n;i++) best[r[i]-l[i]-1]=max(best[r[i]-l[i]-1],a[i]);
    vector<int> res(n+1,0);
    res[n]=best[n];
    for(int i=n-1;i>=1;i--) res[i]=max(best[i],res[i+1]);
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    printf("\n");
	return 0;
}