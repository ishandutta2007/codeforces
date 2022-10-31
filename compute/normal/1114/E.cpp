#include<bits/stdc++.h>
using namespace std;
int main()
{
    mt19937 rnd;
    int n;
    cin>>n;
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        cout<<"> "<<mid<<endl;
        int ret;
        cin>>ret;
        if(ret)
            l=mid+1;
        else r=mid;
    }
    //cout<<"top:"<<r<<endl;
    int ans=0;
    vector<int> all;
    for(int i=0;i<29;i++)
    {
        int cur=rnd()%n+1;
        cout<<"? "<<cur<<endl;
        int ret;
        cin>>ret;
        all.push_back(ret);
    }
    for(int i=0;i<all.size();i++)
    {
        for(int j=i+1;j<all.size();j++)
        {
            ans=__gcd(ans,abs(all[i]-all[j]));
        }
    }
    cout<<"! "<<r-(n-1)*ans<<" "<<ans<<endl;
}