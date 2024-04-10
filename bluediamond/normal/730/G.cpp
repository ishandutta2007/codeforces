#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200+5;

struct segment
{
    ll st;
    ll dr;
};

bool cmp(segment a,segment b)
{
    return a.st<b.st;
}

segment gol[N];
int have=0;

inline void add(segment a)
{
    if(a.st<=a.st)
        gol[++have]=a;
}

inline void del(int id)
{
    have--;
    for(int j=id;j<=have;j++)
        gol[j]=gol[j+1];
}

inline void refresh()
{
    sort(gol+1,gol+have+1,cmp);
}

inline void PrintSolution(segment a)
{
    cout<<a.st<<" "<<a.dr<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    add({1LL,(1LL<<60)});
    int Questions;
    cin>>Questions;
    for(int ppp=1;ppp<=Questions;ppp++)
    {
        refresh();
        ll st,dr;
        ll len;
        cin>>st>>len;
        dr=st+len-1;
        int ID=0;
        for(int i=1;i<=have;i++)
        {
            if(gol[i].st<=st)
                ID=i;
            else
                break;
        }
        if(ID)
        {
            ll RightBorder=gol[ID].dr;
            if(dr<=RightBorder)
            {
                PrintSolution({st,dr});
                add({gol[ID].st,st-1});
                add({dr+1,RightBorder});
                del(ID);
                continue;
            }
        }
        for(int i=1;i<=have;i++)
        {
            ll have=gol[i].dr-gol[i].st+1;
            if(len<=have)
            {
                PrintSolution({gol[i].st,gol[i].st+len-1});
                add({gol[i].st+len,gol[i].dr});
                del(i);
                break;
            }
        }
    }
    return 0;
}
/**

**/