#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > factor;
void fac(long long n)
{
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            factor.push_back(make_pair(i,cnt));
        }
    }
    if(n>1) factor.push_back(make_pair(n,1));
}
int main()
{
    long long n,b;
    cin>>n>>b;
    fac(b);
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<factor.size();i++)
    {
        long long cur=factor[i].first;
        long long cnt=0;
        long long temp=n;
        while(temp)
        {
            cnt+=temp/cur;
            temp/=cur;
        }
        ans=min(ans,cnt/factor[i].second);
    }
    cout<<ans<<endl;
}