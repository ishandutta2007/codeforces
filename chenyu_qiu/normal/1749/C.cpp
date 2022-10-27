#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,i,j;
        cin>>n;
        vector<long long int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        for(i=n;i>=0;i--)
        {
            multiset<long long int> ms;
            for(j=0;j<n;j++)
                ms.insert(v[j]);
            for(j=1;j<=i;j++)
            {
                long long int val=i-j+1;
                multiset<long long int>::iterator it=ms.upper_bound(val);
                if(it==ms.begin())
                    break;
                it--;
                ms.erase(it);
                if(!ms.empty()){
                long long int temp = *ms.begin();
                ms.erase(ms.begin());
                ms.insert(temp+val);}
            }
            if(j==i+1)
                break;
        }
        cout<<i<<"\n";
    }
}