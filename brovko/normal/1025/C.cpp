#include <iostream>
#include <string>

using namespace std;
int n, k, Max, pos;
string s;

int main()
{
    cin >> s;
    n=s.length();
    pos=-1;
    for(int i=0;i<n-1;i++)
        if(s[i+1]==s[i])
        pos=i;
    if(pos==-1)
    {
        cout << n;
        return 0;
    }
    Max=1;
    k=1;
    for(int i=pos+1;i<n-1;i++)
    {
        if(s[i+1]==s[i])
        {
            Max=max(Max, k);
            k=1;
        }
        else k++;
    }
      if(s[0]==s[n-1])
        {
            Max=max(Max, k);
            k=1;
        }
        else k++;
    for(int i=0;i<pos;i++)
    {
        if(s[i+1]==s[i])
        {
            Max=max(Max, k);
            k=1;
        }
        else k++;
    }
    Max=max(Max, k);
    cout << Max;
    return 0;
}