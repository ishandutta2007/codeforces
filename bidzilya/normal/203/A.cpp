#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int x,t,a[301],b[301],da,db;
    cin >> x >> t >> a[0] >> b[0] >> da >> db;
    for (int i=1;i<t;i++)
    {
        a[i] = a[i-1]-da;
        b[i] = b[i-1]-db;
    }
    a[t] = 0;
    b[t] = 0;
    for (int v1=0;v1<=t;v1++)
        for (int v2=0;v2<=t;v2++)
            if (a[v1]+b[v2]==x)
            {
                               cout << "YES";
                               return 0;
            }
    cout << "NO";
    return 0;
}