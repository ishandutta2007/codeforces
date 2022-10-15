#include <bits/stdc++.h>

using namespace std;

int first,n;
bool check(int key)
{
    for(int i=1;i*i<=key;i++)
        if(key%i==0)
        {
            if(2<=i && i<=first)
                return 0;
            if(2<=key/i && key/i<=first)
                return 0;
        }
    return 1;
}
int main()
{///fara deci
    cin>>first>>n;
    while(n>first && !check(n))
        n--;
    if(check(n))
        cout<<n;
    else
        cout<<-1;
    return 0;
}
/**

**/