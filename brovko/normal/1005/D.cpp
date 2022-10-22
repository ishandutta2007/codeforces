#include <iostream>
#include <string>

using namespace std;
string s;
int n, a[200003], i, k;

int main()
{
    cin >> s;
    n=s.length();
    for(i=0;i<n;i++)
        a[i]=((int)s[i]-(int)'0')%3;
    a[n]=3;
    i=0;
    while(i<n)
    {
        if(a[i]==0)
        {
            i++;
            k++;
        }
        else
            if(a[i]==1 && a[i+1]==2)
        {
            k++;
            i=i+2;
        }
        else
            if(a[i]==1 && a[i+1]==1 && i+2<n)
        {
            k++;
            i=i+3;
        }
        else
            if(a[i]==2 && a[i+1]==1)
        {
            k++;
            i=i+2;
        }
        else
            if(a[i]==2 && a[i+1]==2 && i+2<n)
            {
                k++;
                i=i+3;
            }
            else
                i++;
    }
    cout << k;
    return 0;
}