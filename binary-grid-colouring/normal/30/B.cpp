#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int D,M,Y;
int d,m,y;
int a[3];

int check()
{
	if(m<M)return 1;
	else if(m==M)return d<=D;
	return 0;
}
int main()
{
	scanf("%d.%d.%d",&D,&M,&Y);
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	do
	{
		d = a[0], m = a[1], y = a[2];
		if(m>12) continue;
		//leap year failed 
		if(d > (day[m] + (y%4==0 && m==2))) continue;
		
		if(Y - y > 18 || (Y - y == 18 && check()))
		{
			cout<<"YES"<<endl;exit(0);
		}
	}while(next_permutation(a,a+3));
	cout<<"NO"<<endl;	
	return 0;
}