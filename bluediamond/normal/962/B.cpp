#include <iostream>

using namespace std;

const int N=200000;
int n,a,b;
int v[N+5],y=0;

char ch;
char last;
int main()
{
    cin>>n>>a>>b;
    cin.get();

    last='*';
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        if(ch=='.' && last=='*')
            y++;
        if(ch=='.')
            v[y]++;
        last=ch;
    }
    int st=a+b;
    for(int i=1;i<=n;i++)
    {
        int val=(v[i]+1)/2;
        if(a>b)
            swap(a,b);
        if(b>=val)
            b-=val;
        else
            b=0;
        val=v[i]-val;
        if(a>=val)
            a-=val;
        else
            a=0;
    }
    cout<<st-(a+b);
    return 0;
}
/**
9 2 4
*...*...*

**/