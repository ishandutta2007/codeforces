#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, fo=0;
    cin>>k;
    char ar[5]={'a', 'e', 'i', 'o', 'u'};
    for(int a=1; a<=k; a++)
    {
        if(k%a==0 and a>=5 and k/a>=5)
        {
            for(int b=0; b<a; b++)
            {
                for(int c=0; c<k/a; c++)
                {
                    cout<<ar[(b+c)%5];
                }
            }
            exit(0);
        }
    }
    cout<<-1;
}