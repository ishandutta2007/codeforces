#include <bits/stdc++.h>
using namespace std;
struct el
{
    int su=0;
    el *l=0, *r=0;
};
el rt;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        el *cu=&rt;
        for(int b=29; b>=0; b--)
        {
            (*cu).su++;
            if((*cu).l==0) (*cu).l=new el;
            if((*cu).r==0) (*cu).r=new el;
            if(x&(1<<b)) cu=(*cu).r;
            else cu=(*cu).l;
        }
        (*cu).su++;
    }
    for(int a=0; a<n; a++)
    {
        el *cu=&rt;
        int x=0;
        for(int b=29; b>=0; b--)
        {
            (*cu).su--;
            if(ar[a]&(1<<b))
            {
                if((*(*cu).r).su) cu=(*cu).r;
                else
                {
                    cu=(*cu).l, x+=(1<<b);
                }
            }
            else
            {
                if((*(*cu).l).su) cu=(*cu).l;
                else
                {
                    cu=(*cu).r, x+=(1<<b);
                }
            }
        }
        (*cu).su--;
        printf("%d ", x);
    }
}