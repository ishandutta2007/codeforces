#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin>>s;
    ll n=(s[0]-'0')*10000+(s[2]-'0')*1000+(s[4]-'0')*100+(s[3]-'0')*10+(s[1]-'0');
    ll r=1;
    for(int i=0;i<5;i++)r=(r*n)%100000;
    printf("%05I64d\n",r);
}