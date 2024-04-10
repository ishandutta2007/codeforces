#include <iostream>
using namespace std;
int main()
{
    int n,i,s=0;
    string a;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(a=="Tetrahedron")
            s+=4;
        if(a=="Cube")
            s+=6;
        if(a=="Octahedron")
            s+=8;
        if(a=="Dodecahedron")
            s+=12;
        if(a=="Icosahedron")
            s+=20;
    }
    cout<<s;
    return 0;
}