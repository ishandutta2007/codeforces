#include<bits/stdc++.h>
using namespace std;
int readtime(){
	string s;
	getline(cin,s);
	int h,m;
	char c;
	sscanf(s.data(),"[%d:%d %c.m]",&h,&m,&c);
	if(h==12)
		h=0;
	int time=h*60+m;
	if(c=='p')
		time+=12*60;
	return time;
}
int a[100];
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)	
		a[i]=readtime();
	int ans=1,t=0,ptr=0;
	for(;;t++)
	{
		if(t==1440)
			ans++,
			t=0;
		for(int i=0;i<10&&ptr<n&&a[ptr]==t;i++,ptr++);
		if(!(n-ptr))
			break;
	}
	cout<<ans;
}