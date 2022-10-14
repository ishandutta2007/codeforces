#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n;
cin>>n;
cout<<(n>2?(n-2*(n%6<1))*(n-1)*(n-3+n%2):n);
}