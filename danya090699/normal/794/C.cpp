#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s1, s2;
    cin>>s1>>s2;
    int n=s1.size();
    char ol[n], ig[n], an[n];
    for(int a=0; a<n; a++)
    {
        ol[a]=s1[a], ig[a]=s2[a];
    }
    sort(ol, ol+n);
    sort(ig, ig+n, greater <int>());
    int a, oyk=0, iyk=0, yk;
    bool st=1;
    for(a=0; a<n; a++)
    {
        if(a==n-1)
        {
            if(a%2==0) an[a]=ol[oyk];
            else an[a]=ig[iyk];
        }
        else
        {
            if(a%2==0)
            {
                if(ol[oyk]<ig[iyk])
                {
                    an[a]=ol[oyk];
                    oyk++;
                }
                else break;
            }
            else
            {
                if(ol[oyk]<ig[iyk])
                {
                    an[a]=ig[iyk];
                    iyk++;
                }
                else break;
            }
        }
    }
    yk=n-1, oyk=n-n/2-1, iyk=n/2-1;
    for(a; a<n; a++)
    {
        if(a%2==0)
        {
            an[yk]=ol[oyk], oyk--;
        }
        else
        {
            an[yk]=ig[iyk], iyk--;
        }
        yk--;
    }
    for(int a=0; a<n; a++) cout<<an[a];
}