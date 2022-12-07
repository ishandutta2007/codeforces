#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) ar[a]=1;
    if(k>1) k>>=1;
    for(int a=1; a<n/k; a++)
    {
        for(int b=0; (b<a and b+a<n/k); b++)
        {
            for(int c=b; c<n/k; c+=a)
            {
                for(int d=0; d<k; d++)
                {
                    cout<<"? "<<c*k+d+1<<"\n";
                    char an;
                    cin>>an;
                    if(an=='Y') ar[c*k+d]=0;
                }
            }
            cout<<"R\n";
        }
    }
    int an=0;
    for(int a=0; a<n; a++) an+=ar[a];
    cout<<"! "<<an;
}