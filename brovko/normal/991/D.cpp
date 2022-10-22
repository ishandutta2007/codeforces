#include <iostream>
#include <string>

using namespace std;
string s, s1;
int k, n;

int main()
{
    cin >> s;
    cin >> s1;
    n=s.length();
    k=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i+1]=='0' && s1[i]=='0' && s[i]=='0')
           {
               k++;
               s[i+1]='X';
               s1[i]='X';
               s[i]='X';
           }
        if(s[i]=='0' && s1[i]=='0' && s1[i+1]=='0')
           {
               k++;
               s[i]='X';
               s1[i]='X';
               s1[i+1]='X';
           }
        if(s[i+1]=='0' && s1[i]=='0' && s1[i+1]=='0')
           {
               k++;
               s[i+1]='X';
               s1[i]='X';
               s1[i+1]='X';
           }
        if(s[i+1]=='0' && s[i]=='0' && s1[i+1]=='0')
           {
               k++;
               s[i+1]='X';
               s[i]='X';
               s1[i+1]='X';
           }
    }
    cout << k;
    return 0;
}