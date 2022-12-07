#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, an=0;
    cin>>n;
    vector <int> re;
    for(int a=100; a>0; a--)
    {
        if(n-a>0)
        {
            int x=n-a, q=0;
            while(x>0)
            {
                q+=x%10, x/=10;
            }
            if(q==a)
            {
                an++, re.push_back(n-a);
            }
        }
    }
    cout<<an<<"\n";
    for(int a=0; a<re.size(); a++) cout<<re[a]<<"\n";
}