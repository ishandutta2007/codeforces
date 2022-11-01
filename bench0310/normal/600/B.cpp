#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        int l=-1,r=n;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(a[mid]<=b[i]) l=mid;
            else r=mid;
        }
        printf("%d%c",l+1," \n"[i==m-1]);
    }
    return 0;
}