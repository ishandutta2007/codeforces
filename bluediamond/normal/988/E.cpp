#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll val;
int bst=(1<<30);

int v[100],n=0;

int cost(int p1,int p2)
{
    int value=0;
    if(p1<p2)
        value=(n-1-p1)+(n-p2);
    else
        value=(n-p1)+(n-p2);
    return value;
}

void no_primul()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(i==j)
                continue;
            int a=v[i];
            int b=v[j];
            int sum=10*a+b;
            if(sum%25!=0)
                continue;
            bst=min(bst,cost(i,j));
        }
    }
}

#define x first
#define i second

pair<int,int>aux[100];

void i_is_primul()
{
    int i=1;
    for(int j=2;j<=n;j++)
    {
        int a=v[i];
        int b=v[j];
        int sum=10*a+b;
        if(sum%25!=0)
            continue;
        int poz=0;
        if(j==2)
            poz=3;
        else
            poz=2;
        if(v[poz]!=0)
        {
            bst=min(bst,cost(i,j));
            continue;
        }
        for(int k=1;k<=n;k++)
        {
            aux[k].i=k;
            aux[k].x=v[k];
        }
        int who=-1;
        for(int k=poz+1;k<=n;k++)
            if(v[k]!=0)
            {
                who=k;
                break;
            }
        if(who==-1)
            continue;
        int value=0;
        while(who!=poz)
        {
            swap(aux[who],aux[who-1]);
            who--;
            value++;
        }
        int p1=0,p2=0;
        for(int k=1;k<=n;k++)
        {
            if(aux[k].i==i)
                p1=k;
            if(aux[k].i==j)
                p2=k;
        }
        bst=min(bst,value+cost(p1,p2));
    }
}

void j_is_primul()
{
    int j=1;
    for(int i=2;i<=n;i++)
    {
        int a=v[i];
        int b=v[j];
        int sum=10*a+b;
        if(sum%25!=0)
            continue;
        int poz=0;
        if(i==2)
            poz=3;
        else
            poz=2;
        if(v[poz]!=0)
        {
            bst=min(bst,cost(i,j));
            continue;
        }
        for(int k=1;k<=n;k++)
        {
            aux[k].i=k;
            aux[k].x=v[k];
        }
        int who=-1;
        for(int k=poz+1;k<=n;k++)
            if(v[k]!=0)
            {
                who=k;
                break;
            }
        if(who==-1)
            continue;
        int value=0;
        while(who!=poz)
        {
            swap(aux[who],aux[who-1]);
            who--;
            value++;
        }
        int p1=0,p2=0;
        for(int k=1;k<=n;k++)
        {
            if(aux[k].i==i)
                p1=k;
            if(aux[k].i==j)
                p2=k;
        }
        bst=min(bst,value+cost(p1,p2));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>val;
    if(val<100)
    {
        if(val==25 || val==50 || val==75)
        {
            cout<<"0\n";
            return 0;
        }
        if(val==52 || val==57)
        {
            cout<<"1\n";
            return 0;
        }
        cout<<"-1\n";
        return 0;
    }
    while(val>0)
    {
        v[++n]=val%10;
        val/=10;
    }
    reverse(v+1,v+n+1);
    no_primul();
    i_is_primul();
    j_is_primul();
    if(bst==(1<<30))
        cout<<"-1\n";
    else
        cout<<bst<<"\n";
    return 0;
}
/**
50267
**/