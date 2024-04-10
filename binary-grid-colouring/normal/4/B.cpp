#include<bits/stdc++.h>
using namespace std;
struct node
{
	int minn;
	int maxx,sub,ans;
}a[35];
int main()
{
	int day,sumtime;
	int summax=0;
	int summin=0;
	cin>>day>>sumtime;
	for(int i=0;i<day;i++)
	{
		
		cin>>a[i].minn>>a[i].maxx;
		 a[i].sub=a[i].maxx-a[i].minn;
		 summax += a[i].maxx;
		 summin += a[i].minn;
		 a[i].ans = a[i].minn;
	}
	if(sumtime > summax || sumtime <summin){
		return 0*printf("NO");
	}
	else // 
	{
		int j=0;
		int tmp=sumtime-summin; 
		while(tmp>0)
		{
			a[j].ans += a[j].sub;
			tmp -= a[j].sub;
			if(tmp >= 0)j++;
		}
		a[j].ans += tmp;
	}
	printf("YES\n");
	for(int i=0;i<day;i++){
		cout<<a[i].ans<<" ";
	}
	cout<<endl;
	return 0;
}