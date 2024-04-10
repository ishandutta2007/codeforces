#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int x1=0,y1=0,x2=1,y2=0,x,y,count=0,i,j=1;
    cin>>x>>y;
    for(i=4;;i++)
    {
        if(min(x1,x2)<=x && max(x1,x2)>=x && min(y1,y2)<=y && max(y1,y2)>=y)break;
        x1=x2;y1=y2;
        if(i%4==0)
        {
            y2+=j;
            j++;count++;
        }
        else if(i%4==1){x2-=j;count++;}
        else if(i%4==2){y2-=j;j++;count++;}
        else {x2+=j;count++;}
    }
    cout<<count;
    return 0;
}