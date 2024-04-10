#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a,b;
    long int i,j=0,count=0;
    char c[6];
    cin>>a>>b;
    if(a.length()!=b.length())
    {
        cout<<"NO";
        return 0;
    }
    else {
        for(i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                count++;
                c[j++]=a[i];c[j++]=b[i];
                if(count>2)
                {
                    cout<<"NO"; return 0;
                }
            }
        }
    }
    if(c[0]==c[3] && c[1]==c[2])
    cout<<"YES";
    else cout<<"NO";
    return 0;
}