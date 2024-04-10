#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int ar[4][4], pos=0;
    for(int a=0; a<4; a++) for(int b=0; b<4; b++) cin>>ar[a][b];
    for(int a=0; a<4; a++)
    {
        if(ar[a][3])
        {
            if(ar[a][0]==1 or ar[a][1]==1 or ar[a][2]==1) pos=1;
            if(ar[(a+1)%4][0]==1 or ar[(a+2)%4][1]==1 or ar[(a+3)%4][2]==1) pos=1;
        }
    }
    if(pos) cout<<"YES";
    else cout<<"NO";
}