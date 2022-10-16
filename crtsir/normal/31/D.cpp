#include<bits/stdc++.h>
using namespace std;
int w,h,n,top=1,x1[105],x2[105],y1[105],y2[105],t1[105],t2[105],t3[105],t4[105],t5,area[10005];
queue<int>t;
bool flag;
int main(){
	cin>>w>>h>>n;
	x1[top]=0,x2[top]=w,y1[top]=0,y2[top]=h;
	for(int i=0;i<n;i++)
	{
		t.push(i);
		cin>>t1[i]>>t2[i]>>t3[i]>>t4[i];
	}
	while(t.size())
	{
		flag=0;
		t5=t.front();
		t.pop();
		for(int i=1;i<=top;i++)
			if(t1[t5]>=x1[i]&&t3[t5]>=x1[i]&&t1[t5]<=x2[i]&&t3[t5]<=x2[i]
			&&t2[t5]>=y1[i]&&t4[t5]>=y1[i]&&t2[t5]<=y2[i]&&t4[t5]<=y2[i])
			{
				if(t1[t5]==t3[t5])
				{
					if(t2[t5]!=y1[i]||t4[t5]!=y2[i])continue;
					top++;
					x1[top]=t1[t5];x2[top]=x2[i];x2[i]=t1[t5];
					y1[top]=y1[i];y2[top]=y2[i];
				}
				else
				{
					if(t1[t5]!=x1[i]||t3[t5]!=x2[i])continue;
					top++;
					x1[top]=x1[i];x2[top]=x2[i];
					y1[top]=t2[t5];y2[top]=y2[i];y2[i]=t2[t5];
				}
				flag=1;
				break;
	        }
		if(!flag)
			t.push(t5);
	}
	for(int i=1;i<=top;i++)
		area[(x2[i]-x1[i])*(y2[i]-y1[i])]++;
	for(int i=1;i<=w*h;i++)
		while(area[i]!=0)
			cout<<i<<' ',
			area[i]--;
}