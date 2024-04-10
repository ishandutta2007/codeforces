#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n, m;
vector < vector<long long> > d;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    }


int main()
{
    cin >> n;
    
    long long ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s == "Tetrahedron") ans+= 4;
        if(s == "Octahedron") ans+= 8;

        if(s == "Dodecahedron") ans+= 12;
        if(s == "Cube") ans+= 6;

        if(s == "Icosahedron") ans+= 20;

    }
    cout << ans;
}