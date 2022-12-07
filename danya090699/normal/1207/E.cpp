#include <bits/stdc++.h>
using namespace std;
main()
{
    int re, an, mask=(1<<7)-1;

    cout<<"? ";
    for(int a=0; a<100; a++) cout<<mask+(a<<7)<<" ";
    cout<<"\n";
    cin>>re;
    an=(re&mask)^mask;
    mask<<=7;
    cout<<"? ";
    for(int a=0; a<100; a++) cout<<mask+a<<" ";
    cout<<"\n";
    cin>>re;
    an+=(re&mask)^mask;
    cout<<"! "<<an<<"\n";
}