#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ifstream i;
    ofstream o;
    i.open("input.txt");
    int n,j;
    string a;
    i>>n;
    i>>a;
    i.close();
    o.open("output.txt");
    for(j=0;j<n/2;j++)
    {
        if(a[j]=='R' && a[j+n/2]=='L')
        o<<j+1+n/2<<" "<<j+1<<endl;
        else
        o<<j+1<<" "<<j+n/2+1<<endl;
        
    }
    o.close();
    return 0;
}