#include <iostream>


using namespace std;

int main()
{
    int a[]={4,7,44,47,74,77,444,474,744,774,447,477,747,777};
    int found=0,n;
    cin>>n;
    for(int i=0;i<14;i++)
    {
        if(n%a[i]==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}