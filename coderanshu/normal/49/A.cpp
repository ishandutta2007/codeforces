#include<bits/stdc++.h>
using namespace std;
// nice concept of 2d array

int main()
{
    ios_base::sync_with_stdio(0);
    string a;
    int i;
    getline(cin,a);
    i=a.length()-1;
    while(a[i]==' ' || a[i]=='?')
    i--;
    if(a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U' || a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='Y' || a[i]=='y' )
    cout<<"YES";
    else cout<<"NO";
    return 0;
}