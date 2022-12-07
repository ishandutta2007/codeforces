//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int de(int x, int y)
{
    int re=x/y;
    if(x%y>0) re++;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, ok=1;
    cin>>n>>k;
    int q4=n, q2=n*2, q1=0, qq2=0, qq1=0;
    for(int a=0; a<k; a++)
    {
        int q;
        cin>>q;
        int x=min(q4, q/4);
        q4-=x, q-=4*x;
        qq2+=q/2;
        qq1+=q%2;
    }
    q2+=q4, q1+=q4;
    int x=min(q2, qq2);
    q2-=x, qq2-=x;
    if(qq2>0)
    {
        if(q1/2>=qq2)
        {
            q1-=qq2*2;
            if(qq1>q1) cout<<"NO";
            else cout<<"YES";
        }
        else cout<<"NO";
    }
    else
    {
        q1+=q2;
        if(qq1>q1) cout<<"NO";
        else cout<<"YES";
    }
}