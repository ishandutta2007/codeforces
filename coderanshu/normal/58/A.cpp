#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[7]={'h','e','l','l','o'};
    string s;
    cin>>s;
    int j,k;
    for(int i=0;i<s.length()-4;i++)
    {
        if(s[i]=='h')
        {
            j=1;
            for(k=i+1;k<s.length();k++)
            {
                if(j==5) break;
               else if(s[k]==c[j])
               j++;
            }
            break;
        }
    }
    if(j==5)cout<<"YES";
    else cout<<"NO";
   return 0; 
}