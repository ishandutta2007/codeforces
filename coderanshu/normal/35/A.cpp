#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,j;
    ifstream i;
    ofstream o;
    i.open("input.txt");
    o.open("output.txt");
    i>>n;
    for(j=0;j<3;j++)
    {
        i>>a;
        i>>b;
        if(a==n || b==n)
        {
            n=n^a^b;
        }
    }
    o<<n;
    i.close();
    o.close();
    return 0;
}