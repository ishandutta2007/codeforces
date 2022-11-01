#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int m[23],r[23];
int main()
{
    int n;
	cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i];
    for(int i=1;i<=n;i++)cin>>r[i];
    int ans1=1;
    for(int i=0;i<=720720;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i%m[j]==r[j])
			{
				ans1++;
				break;
			}
		}
	}                 
   printf("%.10f\n",1.0*ans1/(1.0*720720));
   return 0;
}