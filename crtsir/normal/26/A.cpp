#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,ans=0;
    cin>>n;
    if(n<6)
    {
        cout<<0;
        return 0;
    }
    for(int i=2;i<=n;i++)if(isprime(i))prime.push_back(i);
    for(int i=0;i<prime.size()-1;i++)
        for(int j=i+1;j<prime.size();j++)
            for(int a=1;a*prime[i]<=n;a++)
                for(int b=1;b*prime[j]*a*prime[i]<=n;b++)
                    if(pow(prime[i],a)*pow(prime[j],b)<=n)
                        ans++;
    cout<<ans;
}
/******************/
/*   Name:XianHZ  */
/*   Vedict:AC    */
/*   problem:39H  */
/*time:about 15min*/
/******************/