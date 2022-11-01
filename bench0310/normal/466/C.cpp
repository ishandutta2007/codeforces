#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long a[n];
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    if((sum%3)!=0) return 0*printf("0\n");
    long long goal=sum/3;
    long long left[n],right[n];
    left[0]=a[0];
    for(int i=1;i<n;i++) left[i]=left[i-1]+a[i];
    right[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--) right[i]=right[i+1]+a[i];
    vector<int> v;
    for(int i=0;i<n;i++) if(right[i]==goal) v.push_back(i);
    long long res=0;
    for(int i=0;i<n;i++)
    {
        if(left[i]==goal)
        {
            int l=-1,r=v.size();
            while(l<r-1)
            {
                int mid=(l+r)/2;
                if(v[mid]<i+2) l=mid;
                else r=mid;
            }
            res+=(long long)(v.size()-r);
        }
    }
    printf("%I64d\n",res);
    return 0;
}