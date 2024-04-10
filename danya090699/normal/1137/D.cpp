#include <bits/stdc++.h>
using namespace std;
bool que()
{
    int q, fo=0;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        string s;
        cin>>s;
        int q0=0, q1=0;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='0') q0++;
            if(s[b]=='1') q1++;
        }
        if(q0 and q1) fo=1;
    }
    return fo;
}
int main()
{
    for(int a=0; ; a++)
    {
        if(a%2) cout<<"next 0 1\n";
        else cout<<"next 1\n";

        if(que())
        {
            int cy=0, q=(a+1)/2, q2=0;
            while(1)
            {
                cout<<"next 1\n";
                cy++;
                if(que())
                {
                    while(1)
                    {
                        if(q-cy<q2)
                        {
                            cout<<"next 0 1\n";
                            q++;
                        }
                        else if(q-cy>q2)
                        {
                            cout<<"next 2 3 4 5 6 7 8 9\n";
                            q2++;
                        }
                        else cout<<"next 0 1 2 3 4 5 6 7 8 9\n";

                        int k;
                        cin>>k;
                        string s;
                        for(int b=0; b<k; b++) cin>>s;

                        if(k==1) break;
                    }
                    break;
                }
            }
            break;
        }
    }
    cout<<"done\n";
}