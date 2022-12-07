#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    int n, k;
    cin>>n>>k;
    cout<<de(2*n, k)+de(5*n, k)+de(8*n, k);
}