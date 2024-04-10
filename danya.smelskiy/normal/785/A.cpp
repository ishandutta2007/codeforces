#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (s=="Cube") ans+=6;
        else if (s=="Icosahedron") ans+=20;
        else if (s=="Tetrahedron") ans+=4;
        else if (s=="Dodecahedron") ans+=12;
        else if (s=="Octahedron") ans+=8;
    }
    cout<<ans;
}