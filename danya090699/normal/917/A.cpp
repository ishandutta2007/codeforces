#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    for(int a=0; a<n; a++)
    {
        int vq=0, oq=0, vz=0;
        for(int b=a; b<n; b++)
        {
            bool ok=1;
            if(s[b]=='?')
            {
                vq++;
                if(oq>vz) vz++;
            }
            if(s[b]=='(') oq++;
            if(s[b]==')')
            {
                if(oq)
                {
                    oq--;
                    if(vz>oq) vz--;
                }
                else
                {
                    if(vq) vq--;
                    else ok=0;
                }
            }
            if(ok==0) break;
            if(oq==vz and ((b+1-a)%2==0)) an++;
        }
    }
    cout<<an;
}