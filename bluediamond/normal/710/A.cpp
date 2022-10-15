#include <iostream>
using namespace std;
bool f(int r,int c)
{
    if(r>0 and c>0 and r<=8 and c<=8)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    char ch;
    int c,r,s=0;
    ch=cin.get();
    c=ch-'a'+1;
    cin>>r;
    s+=(f(r-1,c-1));
    s+=(f(r-1,c));
    s+=(f(r-1,c+1));
    s+=(f(r,c-1));
    s+=(f(r,c+1));
    s+=(f(r+1,c-1));
    s+=(f(r+1,c));
    s+=(f(r+1,c+1));
    cout<<s;
    return 0;
}