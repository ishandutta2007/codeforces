//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a2, b2, an=0;
    cin>>n>>a2>>b2;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            int x1=ar[a][0], y1=ar[a][1], x2=ar[b][0], y2=ar[b][1], ok=0;
            if(max(x1, x2)<=a2 and y1+y2<=b2) ok=1;
            if(x1+x2<=a2 and max(y1, y2)<=b2) ok=1;
            swap(x1, y1);
            if(max(x1, x2)<=a2 and y1+y2<=b2) ok=1;
            if(x1+x2<=a2 and max(y1, y2)<=b2) ok=1;
            swap(x1, y1), swap(x2, y2);
            if(max(x1, x2)<=a2 and y1+y2<=b2) ok=1;
            if(x1+x2<=a2 and max(y1, y2)<=b2) ok=1;
            swap(x1, y1);
            if(max(x1, x2)<=a2 and y1+y2<=b2) ok=1;
            if(x1+x2<=a2 and max(y1, y2)<=b2) ok=1;
            if(ok) an=max(an, x1*y1+x2*y2);
        }
    }
    cout<<an;
}