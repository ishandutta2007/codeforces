#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int q1=0, q2=0;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]=='0')
        {
            cout<<1<<" "<<q1+1<<"\n";
            q1++;
            if(q1==4) q1=0;
        }
        else
        {
            cout<<3<<" ";
            if(q2==0)
            {
                cout<<1;
                q2++;
            }
            else
            {
                cout<<3;
                q2=0;
            }
            cout<<"\n";
        }
    }
}