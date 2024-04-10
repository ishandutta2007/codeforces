#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int q8=k/2, q6=k%2;
    if(q8+q6<=18)
    {
        for(int a=0; a<q8; a++) cout<<8;
        if(q6) cout<<6;
    }
    else cout<<-1;
}