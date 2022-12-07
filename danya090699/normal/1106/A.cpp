#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    char fi[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) cin>>fi[a][b];
    for(int a=1; a+1<n; a++)
    {
        for(int b=1; b+1<n; b++)
        {
            if(fi[a][b]=='X' and fi[a-1][b-1]=='X' and fi[a-1][b+1]=='X' and fi[a+1][b-1]=='X' and fi[a+1][b+1]=='X') an++;
        }
    }
    cout<<an;
}