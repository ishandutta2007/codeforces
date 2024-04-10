#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,even_count=0,odd_count=0;
        cin>>n;
        vector<long long int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            if((v[i])%2)
            {
                odd_count++;
            }
            else
            {
                even_count++;
            }
        }
        if(even_count>=odd_count){cout<<odd_count<<"\n";}
        else{cout<<even_count<<"\n";}
    }
    return 0;
}