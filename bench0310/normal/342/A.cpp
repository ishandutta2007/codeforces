#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v(8,0);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v[a]++;
    }
    if(v[1]==n/3&&v[5]==0&&v[7]==0&&v[3]<=v[6]&&v[2]==v[4]+v[6]-v[3])
    {
        while(v[3]--) printf("1 3 6\n");
        while(v[2]--)
        {
            printf("1 2 ");
            if(v[4]-->0) printf("4\n");
            else printf("6\n");
        }
    }
    else printf("-1\n");
	return 0;
}