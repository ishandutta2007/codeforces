#include <iostream>
#include <string>

using namespace std;
int n;
string t, s1;

int main()
{
    cin >> n;
    cin >> t;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            s1=t.substr(0, i);
            for(int j=0;j<i;j++)
                t[j]=s1[i-j-1];
        }
    }
    cout << t;
}