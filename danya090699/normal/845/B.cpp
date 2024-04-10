//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int ar[6];
    for(int a=0; a<6; a++) ar[a]=s[a]-'0';
    int s1=ar[0]+ar[1]+ar[2], s2=ar[3]+ar[4]+ar[5], dif;
    if(s1<s2)
    {
        for(int a=0; a<3; a++) ar[a]=9-ar[a];
        sort(ar, ar+6, greater <int>());
        dif=s2-s1;
    }
    else
    {
        for(int a=3; a<6; a++) ar[a]=9-ar[a];
        sort(ar, ar+6, greater <int>());
        dif=s1-s2;
    }
    int yk=0;
    while(dif>0)
    {
        dif-=ar[yk], yk++;
    }
    cout<<yk;
}