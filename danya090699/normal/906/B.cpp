#include <bits/stdc++.h>
using namespace std;
int n, m, ch=0, ok=1;
int va(int x, int y)
{
    if(ch) return y*n+x;
    else return x*m+y;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    if(n>m)
    {
        swap(n, m), ch=1;
    }
    int an[n][m];
    if(m==1) an[0][0]=0;
    else if(m<3) ok=0;
    else if(m==3)
    {
        if(n==3)
        {
            an[0][0]=0, an[0][1]=2, an[0][2]=3;
            an[1][0]=4, an[1][1]=6, an[1][2]=5;
            an[2][0]=8, an[2][1]=1, an[2][2]=7;
        }
        else ok=0;
    }
    else if(m==4)
    {
        for(int a=0; a<n; a++)
        {
            an[a][0]=va(a, 1), an[a][1]=va(a, 3);
            an[(a+1)%n][2]=va(a, 0), an[(a+1)%n][3]=va(a, 2);
            if(a%2)
            {
                swap(an[a][0], an[a][1]);
                swap(an[(a+1)%n][2], an[(a+1)%n][3]);
            }
        }
    }
    else
    {
        for(int a=0; a<n; a++)
        {
            int yk=a%2;
            for(int b=0; b<m; b+=2)
            {
                an[a][yk]=va(a, b), yk=(yk+1)%m;
            }
            for(int b=1; b<m; b+=2)
            {
                an[a][yk]=va(a, b), yk=(yk+1)%m;
            }
        }
    }
    if(ok)
    {
        cout<<"YES\n";
        if(ch)
        {
            for(int a=0; a<m; a++)
            {
                for(int b=0; b<n; b++) cout<<an[b][a]+1<<" ";
                cout<<"\n";
            }
        }
        else
        {
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<m; b++) cout<<an[a][b]+1<<" ";
                cout<<"\n";
            }
        }
    }
    else cout<<"NO";
}