#include <iostream>
using namespace std;
int main()
{
    int i,n,k,tmp,num;
    cin >>  n >> k;
    for(i=0;i<k;i++)
    {
        cin >> tmp;
        if(tmp==0)
        {
            cout << i << endl;
            return 0;
        }
    }
    for(;i<n;i++)
    {
        cin >> num;
        if(num==0)
        {
            cout << k << endl;
            return 0;
        }
        if(num==tmp) k++;
    }
    cout << k << endl;
    return 0;
}