#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(5,0);
	for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        v[temp]++;
    }
    int res=v[4]+v[3]+v[2]/2;
    v[1]=max(0,v[1]-v[3]);
    if(v[2]&1)
    {
        res++;
        v[1]=max(0,v[1]-2);
    }
    res+=(v[1]+3)/4;
    printf("%d\n",res);
	return 0;
}