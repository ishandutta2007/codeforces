#include <bits/stdc++.h>
using namespace std;
int qm=0, qs=0, ql=0, q[2][3];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        if(s.size()==1)
        {
            if(s=="M") qm++;
            if(s=="S") qs++;
            if(s=="L") ql++;
        }
        else
        {
            if(s.back()=='S') q[0][s.size()-2]++;
            else q[1][s.size()-2]++;
        }
    }
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        if(s.size()==1)
        {
            if(s=="M")
            {
                if(qm) qm--;
                else an++;
            }
            if(s=="L")
            {
                if(ql) ql--;
                else an++;
            }
            if(s=="S")
            {
                if(qs) qs--;
                else an++;
            }
        }
        else
        {
            if(s.back()=='S')
            {
                if(q[0][s.size()-2]) q[0][s.size()-2]--;
                else an++;
            }
            else
            {
                if(q[1][s.size()-2]) q[1][s.size()-2]--;
                else an++;
            }
        }
    }
    cout<<an;
}