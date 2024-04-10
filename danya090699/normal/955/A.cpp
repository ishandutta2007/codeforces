#include <bits/stdc++.h>
using namespace std;
int de(int a, int b){return a/b+(a%b>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int hh, mm;
    cin>>hh>>mm;
    int t=hh*60+mm;
    int h, d, c, n;
    cin>>h>>d>>c>>n;
    cout<<fixed<<setprecision(10)<<min(de(h, n)*c*1.0, de(h+(max(20*60, t)-t)*d, n)*c*0.8);
}