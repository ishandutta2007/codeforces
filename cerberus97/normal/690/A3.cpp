#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int sum=0;
        int n,x;
        cin>>n;
        cin>>x;
        for(int i=1;i<n;i++)
        {
            int g;
            cin>>g;
            sum=sum+g-1;
        }

        for(int i=0;i<=n-1;i++)
        {
            if((sum+i)%n==x-1)
                cout<<i+1<<endl;
        }
    }
    return 0;
}