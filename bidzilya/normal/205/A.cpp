#include <iostream>
#include <iomanip>
using namespace std;

typedef long long lli;

int main()
{
    int n;
    cin >> n;    
    int cnt = 0;
    int min,ind=0;
    for (int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if (ind==0 || a<min)
        {
                   min = a;
                   ind = i+1;
                   cnt = 1;
        }else
        if (a==min)
           cnt++;
    }
    if (cnt>1)
       cout << "Still Rozdil";
    else
        cout << ind;
    return 0;
}