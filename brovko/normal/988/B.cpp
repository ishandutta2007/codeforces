#include <iostream>
#include <string>

using namespace std;
int n, Min, f, f1;
string a[100], c;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n-1;i++)
    {
        Min=i;
        for(int j=i+1;j<n;j++)
            if(a[j].length()<a[Min].length())
                Min=j;
        c=a[i];
        a[i]=a[Min];
        a[Min]=c;
    }
    f=1;
    for(int i=0;i<n-1;i++)
    {
        f1=0;
        for(int j=0;j<=a[i+1].length()-a[i].length();j++)
            if(a[i+1].substr(j, a[i].length())==a[i])
            f1=1;
        f=f*f1;
    }
    if(f==0)
        cout << "NO";
        else
    {
        cout << "YES" << endl;
        for(int i=0;i<n;i++)
            cout << a[i] << endl;
    }
    return 0;
}