#include<bits/stdc++.h>
using namespace std;

string a[12]={ "C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
int func(string s1,string s2)
{
    int i,x,y;
    for(i=0;i<12;i++)
    {
        if(s1.compare(a[i])==0)
        x=i+1;
        if(s2.compare(a[i])==0)
        y=i+1;
    }
    return (x<=y)?y-x:12+y-x;
}

int main()
{
    string b[3];
    int i,j,k;
    cin>>b[0]>>b[1]>>b[2];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                if(func(b[i],b[j])==4 && func(b[j],b[k])==3){cout<<"major";return 0;}
                if(func(b[i],b[j])==3 && func(b[j],b[k])==4){cout<<"minor";return 0;}
            }
        }
    }
    cout<<"strange";
    return 0;
}