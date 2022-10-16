//  228

#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#define endl '\n'
#define space ' '
using namespace std;

struct record
{
    int wins=0,losses=0;
};
int main() {
	int n,i,z;
	cin>>n;
	z=(n*(n-1))/2-1;
	int res[z][2];
	struct record arr[n+1];
	for(i=0;i<z;i++)
	{
	    cin>>res[i][0]>>res[i][1];
	    arr[res[i][0]].wins++;
	    arr[res[i][1]].losses++;
	}
	int p1=0,p2=0;
	for(i=1;i<=n;i++)
	{
	    if(arr[i].wins+arr[i].losses<n-1)
	        (p1==0?p1=i:p2=i);
	}
	if(arr[p1].wins>arr[p2].wins)
	    cout<<p1<<space<<p2;
    else
        cout<<p2<<space<<p1;
	return 0;
}