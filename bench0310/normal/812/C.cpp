#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //copypasting old code solved in a mashup [Nov/27/2018]
    ios::sync_with_stdio(false);
    long long n,s;
    cin >> n >> s;
    long long arr[n];
    long long cs[n];
    long long m=0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        if(i) m=max(m,arr[i-1]-arr[i]);
        if(!i) cs[i]=arr[i];
        else cs[i]=cs[i-1]+arr[i];
    }
    long long l=0,r=n+1;
    long long sum,res=0;
    while(l+1<r)
    {
        long long mid=(l+r)/2;
        sum=0;
        if(mid<m)
        {
            long long t[n];
            for(int i=0;i<n;i++) t[i]=arr[i]+mid*(i+1);
            sort(t,t+n);
            for(int i=0;i<mid;i++) sum+=t[i];
            for(int i=0;i<n;i++) t[i]=arr[i]+mid*(i+1);
        }
        else sum=cs[mid-1]+(mid)*((mid)*(mid+1)/2);
        if(sum<=s)
        {
            l=mid;
            res=sum;
        }
        else r=mid;
    }
    cout << l << " " << res << endl;
    return 0;
}