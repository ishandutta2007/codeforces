#include <iostream>
#include <cstdio>
using namespace std;
 
long long res=10e17,N,p[]={2,3,5,7,11,13,17,19,23,29};
 
void solve(long long w,long long n,long long v)
{
    if(w>9||v>N) return;
    if(v==N&&res>n) res=n;
    for(int i=2;i<99;i++)
    {
	n*=p[w];
	if(n>res) break;
	solve(w+1,n,v*i);
    }
}
 
int main()
{
    cin>>N;
    solve(0,1,1);
    cout<<res;
}