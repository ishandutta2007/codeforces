#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        if(s=="Tetrahedron") an+=4;
        if(s=="Cube") an+=6;
        if(s=="Octahedron") an+=8;
        if(s=="Dodecahedron") an+=12;
        if(s=="Icosahedron") an+=20;
    }
    cout<<an;
}