#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int t,n;
 
    cin >> t;
 
    for(int i=0;i<t;i++)
    {
        long long int x=0;
        cin >> n;
 
        if(n==1)
        {
            cout << 0 << endl;
        }
        else{
        while(n>= (pow(2,x)))
        {
            x++;
        }
        long long int a=(pow(2,(x-1))-1);
        cout << a << endl;
        }
 
 
    }
}