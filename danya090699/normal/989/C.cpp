#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n=50;
    char an[n][n];
    int qa, qb, qc, qd;
    cin>>qa>>qb>>qc>>qd;
    for(int a=0; a<25; a++) for(int b=0; b<50; b++) an[a][b]='A';
    for(int a=0; a<n; a++) an[25][a]='B';
    for(int a=26; a<n; a++) for(int b=0; b<50; b++) an[a][b]='C';
    qa--, qb--, qc--;
    for(int a=0; a<25; a++)
    {
        for(int b=(a%2)*2; b<n; b+=4)
        {
            if(qb)
            {
                an[a][b]='B', qb--;
            }
            else if(qc)
            {
                an[a][b]='C', qc--;
            }
        }
    }
    for(int a=26; a<n; a++)
    {
        for(int b=(a%2)*2; b<n; b+=4)
        {
            if(qa)
            {
                an[a][b]='A', qa--;
            }
            else if(qd)
            {
                an[a][b]='D', qd--;
            }
        }
    }
    cout<<n<<" "<<n<<"\n";
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) cout<<an[a][b];
        cout<<"\n";
    }
}