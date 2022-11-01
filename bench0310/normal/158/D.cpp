#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],res=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        res+=a[i];
    }
    for(int o=1;o<=n;o++)
    {
        if(n%o||(n/o)<3) continue;
        vector<int> v(o,0);
        for(int i=0;i<n;i++) v[i%o]+=a[i];
        for(int i=0;i<o;i++) res=max(res,v[i]);
    }
    printf("%d\n",res);
	return 0;
}