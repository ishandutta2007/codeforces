#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, lg=0, rg=1e9, an=1;
    cin>>n;
    set <int, greater <int> > lse;
    set <int> rse, cse;
    for(int a=0; a<n; a++)
    {
        string ty;
        cin>>ty;
        int x;
        scanf("%d", &x);
        if(ty=="ADD")
        {
            if(x<lg)
            {
                lse.insert(x), lg=*lse.begin();
            }
            else if(x>rg)
            {
                rse.insert(x), rg=*rse.begin();
            }
            else cse.insert(x);
        }
        else
        {
            if(x<=lg)
            {
                if(x!=lg) an=0;
                lse.erase(x);
                if(lse.size()) lg=*lse.begin();
                else lg=0;
                for(auto it=cse.begin(); it!=cse.end(); it++) rse.insert(*it);
                cse.clear();
                if(rse.size()) rg=*rse.begin();
            }
            else if(x>=rg)
            {
                if(x!=rg) an=0;
                rse.erase(x);
                if(rse.size()) rg=*rse.begin();
                else rg=1e9;
                for(auto it=cse.begin(); it!=cse.end(); it++) lse.insert(*it);
                cse.clear();
                if(lse.size()) lg=*lse.begin();
            }
            else
            {
                an=(an*2)%mod;
                cse.erase(x);
                for(auto it=cse.begin(); it!=cse.end(); it++)
                {
                    int va=(*it);
                    if(va<x) lse.insert(va);
                    else rse.insert(va);
                }
                cse.clear();
                if(lse.size()) lg=*lse.begin();
                if(rse.size()) rg=*rse.begin();
            }
        }
        if(an==0) break;
    }
    an=(1ll*an*(int(cse.size())+1))%mod;
    cout<<an;
 }