#include <iostream>
#include <cstring>
using namespace std;
char s[10];
int v[10];
int main()
{
    int n,i,c1,c2,c3,c4,c5,c6,v1,v2,v3,v4,v5,v6,bst=100;
    cin.getline(s,10);
    for(i=1;i<=6;i++)
        v[i]=s[i-1]-'0';
    for(c1=0;c1<2;c1++)
    for(c2=0;c2<2;c2++)
    for(c3=0;c3<2;c3++)
    for(c4=0;c4<2;c4++)
    for(c5=0;c5<2;c5++)
    for(c6=0;c6<2;c6++)
    for(v1=0;v1<10;v1++)
    for(v2=0;v2<10;v2++)
    for(v3=0;v3<10;v3++)
    for(v4=0;v4<10;v4++)
    for(v5=0;v5<10;v5++)
    for(v6=0;v6<10;v6++)
    if(v1!=v[1] and v2!=v[2] and v3!=v[3] and v4!=v[4] and v5!=v[5] and v6!=v[6])
    {
        int s1=0,s2=0;
        if(c1)
            s1+=v1;
        else
            s1+=v[1];
        if(c2)
            s1+=v2;
        else
            s1+=v[2];
        if(c3)
            s1+=v3;
        else
            s1+=v[3];
        if(c4)
            s2+=v4;
        else
            s2+=v[4];
        if(c5)
            s2+=v5;
        else
            s2+=v[5];
        if(c6)
            s2+=v6;
        else
            s2+=v[6];
        if(s1==s2)
        {
            int x=c1+c2+c3+c4+c5+c6;
            if(x<bst)
                bst=x;
        }
    }
    cout<<bst;
    return 0;
}