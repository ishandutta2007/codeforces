#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int re=a/b;
    if(a%b!=0) re++;
    return re;
}
int main()
{
    int l, r;
    cin>>l>>r;
    r++;
    int l2=l+l%2, l3=l, q2=0, q3=0;
    if(l%3==1) l3+=2;
    else if(l%3==2) l3++;
    if(l2<r) q2=de(r-l2, 2);
    if(l3<r) q3=de(r-l3, 3);
    if(l==r-1) cout<<l;
    else
    {
        if(q2>q3) cout<<2;
        else cout<<3;
    }
}